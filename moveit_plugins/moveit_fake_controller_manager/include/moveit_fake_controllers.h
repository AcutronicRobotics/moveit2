/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Ioan A. Sucan
 *  Copyright (c) 2016, Robert Haschke
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the names of the authors nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Ioan Sucan, Robert Haschke */

#include <moveit/macros/class_forward.h>
#include <moveit/controller_manager/controller_manager.h>
#include "rclcpp/rclcpp.hpp"
#include <boost/thread/thread.hpp>
#include <sensor_msgs/msg/joint_state.hpp>

#ifndef MOVEIT_FAKE_CONTROLLERS
#define MOVEIT_FAKE_CONTROLLERS

namespace moveit_fake_controller_manager
{
MOVEIT_CLASS_FORWARD(BaseFakeController);

// common base class to all fake controllers in this package
class BaseFakeController : public moveit_controller_manager::MoveItControllerHandle
{
public:
  BaseFakeController(const std::string& name, const std::vector<std::string>& joints, const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub);

  moveit_controller_manager::ExecutionStatus getLastExecutionStatus() override;
  void getJoints(std::vector<std::string>& joints) const;

protected:
  std::vector<std::string> joints_;
  const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub_;
};

class LastPointController : public BaseFakeController
{
public:
  LastPointController(const std::string& name, const std::vector<std::string>& joints, const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub);
  ~LastPointController() override;

  bool sendTrajectory(const moveit_msgs::msg::RobotTrajectory& t) override;
  bool cancelExecution() override;
  bool waitForExecution(const rclcpp::Duration&) override;
};

class ThreadedController : public BaseFakeController
{
public:
  ThreadedController(const std::string& name, const std::vector<std::string>& joints, const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub);
  ~ThreadedController() override;

  bool sendTrajectory(const moveit_msgs::msg::RobotTrajectory& t) override;
  bool cancelExecution() override;
  bool waitForExecution(const rclcpp::Duration&) override;
  moveit_controller_manager::ExecutionStatus getLastExecutionStatus() override;

protected:
  bool cancelled()
  {
    return cancel_;
  }

private:
  virtual void execTrajectory(const moveit_msgs::msg::RobotTrajectory& t) = 0;
  virtual void cancelTrajectory();

private:
  boost::thread thread_;
  bool cancel_;
  moveit_controller_manager::ExecutionStatus status_;
};

class ViaPointController : public ThreadedController
{
public:
  ViaPointController(const std::string& name, const std::vector<std::string>& joints, const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub);
  ~ViaPointController() override;

protected:
  void execTrajectory(const moveit_msgs::msg::RobotTrajectory& t) override;
};

class InterpolatingController : public ThreadedController
{
public:
  InterpolatingController(const std::string& name, const std::vector<std::string>& joints, const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub,
                          const rclcpp::Node::SharedPtr& node_);
  ~InterpolatingController() override;

protected:
  void execTrajectory(const moveit_msgs::msg::RobotTrajectory& t) override;

private:
  rclcpp::WallRate rate_;
  rclcpp::Node::SharedPtr node_;
};
}

#endif