import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class PythonNode(Node):



    def __init__(self):
        super().__init__('Mission_planner')

        self.tca_scanner_pub = self.create_publisher(
        String, 'Mission_planner', 10)

        self.timer = self.create_timer(0.02, self.mission_loop)


    def mission_loop(self):
        self.get_logger().info(f"Mission Loop {time.time()}")
        msg = String()
        msg.data = f"Mission Loop {time.time()}"
        self.tca_scanner_pub.publish(msg)




def main(args=None):
    rclpy.init(args=args)
    node = PythonNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()