import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from motor_interfaces.msg import MotorCommand


class Teleop(Node):
    def __init__(self):
        super().__init__("teleop")
        self.pub = self.create_publisher(MotorCommand, "motor_cmd", 10)
        self.create_subscription(Joy, "joy", self.on_joy, 10)

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
        self.send(1, "velocity", a[1] * 3.0)
        self.send(2, "velocity", a[1] * 3.0)
        self.send(3, "velocity", -a[4] * 3.0)
        if b[0]:
            self.send(10, "position", 1.0)


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