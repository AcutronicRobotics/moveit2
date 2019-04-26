/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016, Kentaro Wada.
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
 *   * Neither the name of Willow Garage nor the names of its
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

/*
 * Capability of execute trajectory with a ROS action.
 *
 * Author: Kentaro Wada
 * */

#ifndef MOVEIT_MOVE_GROUP_EXECUTE_TRAJECTORY_ACTION_CAPABILITY_
#define MOVEIT_MOVE_GROUP_EXECUTE_TRAJECTORY_ACTION_CAPABILITY_

#include <moveit/move_group/move_group_capability.h>
#include "rclcpp_action/rclcpp_action.hpp"
#include <moveit_msgs/action/execute_trajectory.hpp>
#include <memory>

namespace move_group
{
class MoveGroupExecuteTrajectoryAction : public MoveGroupCapability
{
public:
  MoveGroupExecuteTrajectoryAction();

  void initialize() override;

private:
  void executePathCallback(const std::shared_ptr<rclcpp_action::ServerGoalHandle<moveit_msgs::action::ExecuteTrajectory>> goal_handle);
  void executePath(const std::shared_ptr<rclcpp_action::ServerGoalHandle<moveit_msgs::action::ExecuteTrajectory>> goal_handle,
                   std::shared_ptr<moveit_msgs::action::ExecuteTrajectory::Result> action_res);
  void preemptExecuteTrajectoryCallback();
  void setExecuteTrajectoryState(MoveGroupState state,
     const std::shared_ptr<rclcpp_action::ServerGoalHandle<moveit_msgs::action::ExecuteTrajectory>> goal_handle);
  rclcpp_action::GoalResponse handle_trajectory_goal(const std::array<uint8_t, 16>& uuid,
                                               std::shared_ptr<const moveit_msgs::action::ExecuteTrajectory::Goal> goal);
  rclcpp_action::CancelResponse handle_trajectory_cancel(
     const std::shared_ptr<rclcpp_action::ServerGoalHandle<moveit_msgs::action::ExecuteTrajectory>> goal_handle);

  void handle_trajectory_accept(
     const std::shared_ptr<rclcpp_action::ServerGoalHandle<moveit_msgs::action::ExecuteTrajectory>> goal_handle);

  std::shared_ptr<rclcpp_action::Server<moveit_msgs::action::ExecuteTrajectory>> execute_action_server_;
};

}  // namespace move_group

#endif  // MOVEIT_MOVE_GROUP_EXECUTE_TRAJECTORY_ACTION_CAPABILITY_
