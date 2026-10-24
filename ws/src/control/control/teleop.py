import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from motor_interfaces.msg import MotorCommand
import time

class Teleop(Node):
    def __init__(self):
        super().__init__("teleop")
        self.lastTime = time.time()
        self.pub = self.create_publisher(MotorCommand, "motor_cmd", 10)
        self.create_subscription(Joy, "joy", self.on_joy, 10)

        self.get_logger().info(f"teleop Loop {time.time()}")

    def send(self, mid, command_type, value):
        m = MotorCommand()
        m.id = mid
        m.command_type = command_type   # "velocity" | "position" | "torque"
        m.value = float(value)
        self.pub.publish(m)

    def on_joy(self, msg):
        a = msg.axes        # list of floats, -1.0 .. 1.0
        b = msg.buttons     # list of ints, 0 or 1

        # ---- wire inputs to motors here ----
        self.get_logger().info(f"teleop Loop {time.time()}")
        if time.time() >= self.lastTime + 0.1:
            self.lastTime = time.time()
            if not b[10]:
                self.send(1, "velocity", a[1] * 10.0 * (1-a[0]*0.1))
                self.send(2, "velocity", a[1] * 10.0 * (1-a[0]*0.1))
                self.send(3, "velocity", a[1] * 10.0 * (1-a[0]*0.1))
                self.send(4, "velocity", -a[1] * 10.0 * (1+a[0]*0.1))
                self.send(5, "velocity", -a[1] * 10.0 * (1+a[0]*0.1))
                self.send(6, "velocity", -a[1] * 10.0 * (1+a[0]*0.1))
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