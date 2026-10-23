import math
from threading import Lock

import rclpy
from rclpy.node import Node
from scservo_sdk import PortHandler, PacketHandler, COMM_SUCCESS, SCS_TOSCS
from motor_interfaces.msg import MotorCommand

# STS3215 registers
ADDR_MODE = 33
ADDR_TORQUE = 40
ADDR_GOAL_POS = 42      # 2 bytes
ADDR_GOAL_SPEED = 46    # 2 bytes, sign bit = bit 15 in velocity mode

MODE_POSITION = 0
MODE_VELOCITY = 1

STEPS_PER_REV = 4096


class MotorDriver(Node):
    def __init__(self):
        super().__init__("motor_driver")
        self.declare_parameter("port", "/dev/ttyACM0")
        self.declare_parameter("baud", 1_000_000)
        self.declare_parameter("motor_ids", [1])
        self.declare_parameter("position_speed", 1000)    # steps/s limit in position mode
        self.declare_parameter("max_velocity", 3000)      # steps/s clamp in velocity mode
        self.declare_parameter("center_offset", 2048)     # raw steps corresponding to 0 rad
        self.declare_parameter("watchdog_timeout", 0.5)   # s, stops velocity if no new cmd

        self.motor_ids = set(self.get_parameter("motor_ids").value)
        self.position_speed = self.get_parameter("position_speed").value
        self.max_velocity = self.get_parameter("max_velocity").value
        self.center = self.get_parameter("center_offset").value
        self.wd_timeout = self.get_parameter("watchdog_timeout").value

        self.lock = Lock()
        self.mode = {}            # id -> last mode written
        self.torque = {}          # id -> bool
        self.last_vel_time = {}   # id -> time of last velocity cmd

        self.port = PortHandler(self.get_parameter("port").value)
        if not self.port.openPort():
            raise RuntimeError(f"Can't open {self.get_parameter('port').value}")
        self.port.setBaudRate(self.get_parameter("baud").value)
        self.ph = PacketHandler(0)

        self.handlers = {
            "position": self.cmd_position,
            "velocity": self.cmd_velocity,
            "torque": self.cmd_torque,
        }
        self.create_subscription(MotorCommand, "motor_cmd", self.on_cmd, 10)
        self.create_timer(0.1, self.watchdog)
        self.get_logger().info(f"Driving motors {sorted(self.motor_ids)}")

    # ---- low-level helpers ----
    def w1(self, mid, addr, val):
        r, e = self.ph.write1ByteTxRx(self.port, mid, addr, val)
        return self._ok(r, e, mid, addr)

    def w2(self, mid, addr, val):
        r, e = self.ph.write2ByteTxRx(self.port, mid, addr, val)
        return self._ok(r, e, mid, addr)

    def _ok(self, r, e, mid, addr):
        if r != COMM_SUCCESS:
            self.get_logger().error(
                f"ID {mid} addr {addr}: {self.ph.getTxRxResult(r)}")
            return False
        if e:
            self.get_logger().warn(f"ID {mid} addr {addr}: servo error flags {e}")
        return True

    def set_torque(self, mid, on):
        if self.w1(mid, ADDR_TORQUE, 1 if on else 0):
            self.torque[mid] = on

    def set_mode(self, mid, mode):
        if self.mode.get(mid) == mode:
            return True
        self.set_torque(mid, False)                  # change mode with torque off
        if not self.w1(mid, ADDR_MODE, mode):
            return False
        self.mode[mid] = mode
        self.last_vel_time.pop(mid, None)
        if mode == MODE_POSITION:
            self.w2(mid, ADDR_GOAL_SPEED, self.position_speed)
        else:
            self.w2(mid, ADDR_GOAL_SPEED, 0)
        return True

    def ensure_torque(self, mid):
        if not self.torque.get(mid, False):
            self.set_torque(mid, True)

    # ---- command handlers ----
    def cmd_position(self, mid, value):
        """value in radians, relative to center_offset."""
        if not self.set_mode(mid, MODE_POSITION):
            return
        self.ensure_torque(mid)
        raw = int(round(value / (2 * math.pi) * STEPS_PER_REV)) + self.center
        raw = max(0, min(STEPS_PER_REV - 1, raw))
        self.w2(mid, ADDR_GOAL_POS, raw)

    def cmd_velocity(self, mid, value):
        """value in rad/s."""
        if not self.set_mode(mid, MODE_VELOCITY):
            return
        self.ensure_torque(mid)
        steps = int(round(value / (2 * math.pi) * STEPS_PER_REV))
        steps = max(-self.max_velocity, min(self.max_velocity, steps))
        self.w2(mid, ADDR_GOAL_SPEED, SCS_TOSCS(steps, 15))
        if steps != 0:
            self.last_vel_time[mid] = self.get_clock().now()
        else:
            self.last_vel_time.pop(mid, None)

    def cmd_torque(self, mid, value):
        """value > 0.5 enables torque, otherwise disables."""
        self.set_torque(mid, value > 0.5)

    # ---- ROS plumbing ----
    def on_cmd(self, msg):
        if msg.id not in self.motor_ids:
            self.get_logger().warn(f"Unknown motor id {msg.id}")
            return
        handler = self.handlers.get(msg.command_type)
        if handler is None:
            self.get_logger().warn(f"Unknown command type '{msg.command_type}'")
            return
        with self.lock:
            handler(msg.id, msg.value)

    def watchdog(self):
        now = self.get_clock().now()
        with self.lock:
            for mid, t in list(self.last_vel_time.items()):
                if (now - t).nanoseconds * 1e-9 > self.wd_timeout:
                    self.get_logger().warn(f"ID {mid}: velocity watchdog, stopping")
                    self.w2(mid, ADDR_GOAL_SPEED, 0)
                    del self.last_vel_time[mid]

    def destroy_node(self):
        with self.lock:
            for mid in self.motor_ids:
                self.w2(mid, ADDR_GOAL_SPEED, 0) if self.mode.get(mid) == MODE_VELOCITY else None
                self.set_torque(mid, False)
        self.port.closePort()
        super().destroy_node()


def main():
    rclpy.init()
    node = MotorDriver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()