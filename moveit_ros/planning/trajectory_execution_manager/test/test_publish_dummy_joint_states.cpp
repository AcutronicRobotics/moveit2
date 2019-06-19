#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <fstream>      // std::ifstream

#include "rclcpp/clock.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time_source.hpp"

#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("dummy_joint_states");

  std::string nombre_srdf(argv[1]);

  std::ifstream t(nombre_srdf);
  std::string str;

  t.seekg(0, std::ios::end);
  str.reserve(t.tellg());
  t.seekg(0, std::ios::beg);

  str.assign((std::istreambuf_iterator<char>(t)),
              std::istreambuf_iterator<char>());

  rmw_qos_profile_t qos = rmw_qos_profile_default;
  qos.depth = 1;
  qos.durability = RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL;

  node->declare_parameter("robot_description_kinematics.manipulator.kinematics_solver", "kdl_kinematics_plugin/KDLKinematicsPlugin");
  node->declare_parameter("moveit_controller_manager", "moveit_simple_controller_manager/MoveItSimpleControllerManager");
  node->declare_parameter("planning_plugin", "ompl_interface/OMPLPlanner");
  node->declare_parameter("controller_list.name","fake_arm_controller");
  node->declare_parameter("moveit_manage_controllers", true);
  node->declare_parameter("allow_trajectory_execution", true);
  // auto parameters_client = std::make_shared<rclcpp::SyncParametersClient>(node);
  //
  // parameters_client->set_parameters({rclcpp::Parameter("moveit_controller_manager", "moveit_simple_controller_manager/MoveItSimpleControllerManager")});

  auto robot_description_semantic_pub = node->create_publisher<std_msgs::msg::String>(
    "robot_description_semantic", qos);
  auto msg_robot_description_semantic = std::make_shared<std_msgs::msg::String>();
  msg_robot_description_semantic->data = str;
  robot_description_semantic_pub->publish(msg_robot_description_semantic);

  auto joint_state_pub = node->create_publisher<sensor_msgs::msg::JointState>(
    "joint_states");

  rclcpp::WallRate loop_rate(50);

  auto msg = std::make_shared<sensor_msgs::msg::JointState>();
  msg->name.push_back("motor1");
  msg->name.push_back("motor2");
  msg->name.push_back("motor3");
  msg->name.push_back("motor4");
  msg->name.push_back("motor5");
  msg->name.push_back("motor6");
  msg->position.push_back(0.0);
  msg->position.push_back(0.0);
  msg->position.push_back(0.0);
  msg->position.push_back(0.0);
  msg->position.push_back(0.0);
  msg->position.push_back(0.0);

  // while (rclcpp::ok()) {
  //
  //   rclcpp::TimeSource ts(node);
  //   rclcpp::Clock::SharedPtr clock = std::make_shared<rclcpp::Clock>(RCL_ROS_TIME);
  //   ts.attachClock(clock);
  //   msg->header.stamp = clock->now();
  //
  //   joint_state_pub->publish(msg);
  //   rclcpp::spin_some(node);
  //   loop_rate.sleep();
  // }
  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}
