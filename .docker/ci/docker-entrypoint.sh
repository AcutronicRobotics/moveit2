#!/bin/bash
set -e


find /opt/ros/$ROS_DISTRO/ -name class_loader | xargs rm -rf && find /opt/ros/$ROS_DISTRO -name pluginlib | xargs rm -rf
# setup ros2 environment
source "/opt/ros/$ROS_DISTRO/setup.bash"
exec "$@"
