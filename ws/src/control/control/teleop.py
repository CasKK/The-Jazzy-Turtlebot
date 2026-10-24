import os
import time
from datetime import datetime

import rclpy
from rclpy.node import Node
from rclpy.serialization import serialize_message, deserialize_message
import rosbag2_py
from sensor_msgs.msg import Joy
from motor_interfaces.msg import MotorCommand

BTN_RECORD = 2   # X: start/stop recording
BTN_REPLAY = 3   # Y: start/stop replay
BTN_MODE = 10    # your existing mode switch (right stick click)

IDLE, RECORDING, REPLAYING = "idle", "recording", "replaying"
TOPIC = "/motor_cmd"
TYPE = "motor_interfaces/msg/MotorCommand"


class Teleop(Node):
    def __init__(self):
        super().__init__("teleop")
        self.declare_parameter("bag_dir", "/ws/bags")
        self.bag_dir = self.get_parameter("bag_dir").value
        os.makedirs(self.bag_dir, exist_ok=True)

        self.lastTime = time.time()
        self.state = IDLE
        self.prev_buttons = []
        self.writer = None
        self.rec_path = None
        self.last_bag = self.latest_bag()
        self.replay_msgs = []
        self.replay_i = 0
        self.replay_t0 = 0
        self.replay_timer = None

        self.pub = self.create_publisher(MotorCommand, "motor_cmd", 10)
        self.create_subscription(Joy, "joy", self.on_joy, 10)
        self.create_subscription(MotorCommand, "motor_cmd", self.on_motor_cmd, 50)
        self.get_logger().info("teleop ready")

    # ---------- publishing ----------
    def send(self, mid, command_type, value):
        m = MotorCommand()
        m.id = mid
        m.command_type = command_type   # "velocity" | "position" | "torque"
        m.value = float(value)
        self.pub.publish(m)

    # ---------- joystick ----------
    def on_joy(self, msg):
        a, b = msg.axes, msg.buttons
        if len(self.prev_buttons) != len(b):
            self.prev_buttons = [0] * len(b)
        rising = [bool(now) and not prev for now, prev in zip(b, self.prev_buttons)]
        self.prev_buttons = list(b)

        if rising[BTN_RECORD]:
            self.toggle_record()
        if rising[BTN_REPLAY]:
            self.toggle_replay()

        if self.state == REPLAYING:
            return                      # sticks ignored during replay
        self.drive(a, b)

    def drive(self, a, b):
        if time.time() < self.lastTime + 0.1:
            return
        self.lastTime = time.time()
        if not b[BTN_MODE]:
            self.send(1, "velocity", a[1] * 10.0 * (1 - a[0] * 0.1))
            self.send(2, "velocity", a[1] * 10.0 * (1 - a[0] * 0.1))
            self.send(3, "velocity", a[1] * 10.0 * (1 - a[0] * 0.1))
            self.send(4, "velocity", -a[1] * 10.0 * (1 + a[0] * 0.1))
            self.send(5, "velocity", -a[1] * 10.0 * (1 + a[0] * 0.1))
            self.send(6, "velocity", -a[1] * 10.0 * (1 + a[0] * 0.1))
            self.send(7, "position", a[0] * 1)
            self.send(8, "position", -a[0] * 1)
            self.send(9, "position", -a[0] * 1)
            self.send(10, "position", a[0] * 1)
        else:
            self.send(1, "velocity", a[0] * 10.0)
            self.send(2, "velocity", a[0] * 10.0)
            self.send(3, "velocity", a[0] * 10.0)
            self.send(4, "velocity", -a[0] * 10.0)
            self.send(5, "velocity", -a[0] * 10.0)
            self.send(6, "velocity", -a[0] * 10.0)
            self.send(7, "position", 1)
            self.send(8, "position", 1)
            self.send(9, "position", -1)
            self.send(10, "position", -1)

    # ---------- recording ----------
    def toggle_record(self):
        if self.state == IDLE:
            self.start_recording()
        elif self.state == RECORDING:
            self.stop_recording()
        else:
            self.get_logger().warn("Stop the replay before recording")

    def start_recording(self):
        path = os.path.join(self.bag_dir, datetime.now().strftime("motor_%Y%m%d_%H%M%S"))
        self.writer = rosbag2_py.SequentialWriter()
        self.writer.open(
            rosbag2_py.StorageOptions(uri=path, storage_id="sqlite3"),
            rosbag2_py.ConverterOptions("", ""))
        self.writer.create_topic(rosbag2_py.TopicMetadata(
            id=0, name=TOPIC, type=TYPE, serialization_format="cdr"))
        self.rec_path = path
        self.state = RECORDING
        self.get_logger().info(f"Recording to {path}")

    def stop_recording(self):
        self.writer = None              # destroying the writer finalises the bag
        self.last_bag = self.rec_path
        self.state = IDLE
        self.get_logger().info(f"Saved {self.last_bag}")

    def on_motor_cmd(self, msg):
        if self.state == RECORDING:
            self.writer.write(TOPIC, serialize_message(msg),
                              self.get_clock().now().nanoseconds)

    # ---------- replay ----------
    def toggle_replay(self):
        if self.state == IDLE:
            self.start_replay()
        elif self.state == REPLAYING:
            self.get_logger().info("Replay aborted")
            self.stop_replay()
        else:
            self.get_logger().warn("Stop the recording before replaying")

    def start_replay(self):
        path = self.last_bag or self.latest_bag()
        if not path:
            self.get_logger().warn("No bag to replay")
            return
        reader = rosbag2_py.SequentialReader()
        reader.open(
            rosbag2_py.StorageOptions(uri=path, storage_id="sqlite3"),
            rosbag2_py.ConverterOptions("", ""))
        msgs = []
        while reader.has_next():
            _, data, t = reader.read_next()
            msgs.append((t, deserialize_message(data, MotorCommand)))
        if not msgs:
            self.get_logger().warn(f"{path} is empty")
            return
        t0 = msgs[0][0]
        self.replay_msgs = [(t - t0, m) for t, m in msgs]
        self.replay_i = 0
        self.replay_t0 = self.get_clock().now().nanoseconds
        self.replay_timer = self.create_timer(0.005, self.replay_tick)
        self.state = REPLAYING
        self.get_logger().info(f"Replaying {path} ({len(msgs)} msgs)")

    def replay_tick(self):
        elapsed = self.get_clock().now().nanoseconds - self.replay_t0
        while (self.replay_i < len(self.replay_msgs)
               and self.replay_msgs[self.replay_i][0] <= elapsed):
            self.pub.publish(self.replay_msgs[self.replay_i][1])
            self.replay_i += 1
        if self.replay_i >= len(self.replay_msgs):
            self.get_logger().info("Replay finished")
            self.stop_replay()

    def stop_replay(self):
        if self.replay_timer is not None:
            self.destroy_timer(self.replay_timer)
            self.replay_timer = None
        for mid in {m.id for _, m in self.replay_msgs if m.command_type == "velocity"}:
            self.send(mid, "velocity", 0.0)
        self.state = IDLE

    # ---------- helpers ----------
    def latest_bag(self):
        dirs = sorted(d for d in os.listdir(self.bag_dir) if d.startswith("motor_"))
        return os.path.join(self.bag_dir, dirs[-1]) if dirs else None

    def destroy_node(self):
        self.writer = None
        super().destroy_node()


def main():
    rclpy.init()
    node = Teleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()