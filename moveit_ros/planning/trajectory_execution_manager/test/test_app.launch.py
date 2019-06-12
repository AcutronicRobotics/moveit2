import sys
import os
import launch

from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch import LaunchDescription
from launch import LaunchService
from launch.actions.execute_process import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    urdf = os.path.join(get_package_share_directory('mara_description'), 'urdf', 'mara_robot_gripper_140.urdf')
    srdf = "/mnt/myfiles/github/moveitmaster/src/dependencies/moveit_resources/mara_moveit_config/config/mara.srdf"
    print(urdf)
    ld = LaunchDescription([
        Node(package='robot_state_publisher', node_executable='robot_state_publisher', output='screen', arguments=[urdf]),
        Node(package='moveit_ros_planning', node_executable='test_publish_dummy_joint_states', output='screen', arguments=[srdf])
    ])
    return ld
