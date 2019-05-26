#!/bin/bash

#set -x #Debug
set -e #exit on failure

#Prepare for ros2
export dir=$(PWD)
cd /tmp
wget https://github.com/AcutronicRobotics/moveit2/releases/download/ci_osx_dashing/ros2_osx.zip
unzip -q ros2_osx.zip
wget https://github.com/AcutronicRobotics/moveit_msgs/releases/download/dashing_pre-release/dashing_pre-release.zip -O moveit_msgs.zip
unzip -q moveit_msgs.zip -d moveit_msgs
wget https://github.com/AcutronicRobotics/octomap_msgs/releases/download/dashing_pre-release/dashing_pre-release.zip -O octomap_msgs.zip
unzip -q octomap_msgs.zip -d octomap_msgs
wget https://github.com/AcutronicRobotics/object_recognition_msgs/releases/download/dashing_pre-release/dashing_pre-release.zip -O object_recognition_msgs.zip
unzip -q object_recognition_msgs.zip -d object_recognition_msgs
cp -r moveit_msgs/dashing_pre-release/* ros2_dashing/
cp -r object_recognition_msgs/dashing_pre-release/* ros2_dashing/
cp -r octomap_msgs/dashing_pre-release/* ros2_dashing/
# Remove tf2_eigen
find ros2-osx/ -name tf2_eigen | xargs rm -rf
find ros2-osx/ -name resource_retriever | xargs rm -rf
