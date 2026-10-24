import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    motor_driver_node = Node(
        package='control',
        executable='motor_driver',
        name='motor_driver',
        output='screen'
    )

    teleop_node = Node(
            package='control',
            executable='teleop',
            name='teleop',
            output='screen'
    )

    return LaunchDescription([
        teleop_node,
        motor_driver_node
    ])


