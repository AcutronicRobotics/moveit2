/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
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

/* Author: Ioan Sucan */

#ifndef MOVEIT_MOVE_GROUP_PICK_PLACE_ACTION_CAPABILITY_
#define MOVEIT_MOVE_GROUP_PICK_PLACE_ACTION_CAPABILITY_

#include <moveit/move_group/move_group_capability.h>
#include "rclcpp_action/rclcpp_action.hpp"
#include <moveit/pick_place/pick_place.h>
#include <moveit_msgs/action/pickup.hpp>
#include <moveit_msgs/action/place.hpp>

#include <memory>

namespace move_group
{
class MoveGroupPickPlaceAction : public MoveGroupCapability
{
public:
  MoveGroupPickPlaceAction();
  void initialize() override;

private:
  void executePickupCallback(const std::shared_ptr<const moveit_msgs::action::Pickup::Goal>& goal);
  void executePlaceCallback(const std::shared_ptr<const moveit_msgs::action::Place::Goal>& goal);

  void executePickupCallbackPlanOnly(const std::shared_ptr<const moveit_msgs::action::Pickup::Goal>& goal,
                                     moveit_msgs::action::Pickup::Result& action_res);
  void executePickupCallbackPlanAndExecute(const std::shared_ptr<const moveit_msgs::action::Pickup::Goal>& goal,
                                           moveit_msgs::action::Pickup::Result& action_res);

  void executePlaceCallbackPlanOnly(const std::shared_ptr<const moveit_msgs::action::Place::Goal>& goal, moveit_msgs::action::Place::Result& action_res);
  void executePlaceCallbackPlanAndExecute(const std::shared_ptr<const moveit_msgs::action::Place::Goal>& goal,
                                          moveit_msgs::action::Place::Result& action_res);

  bool planUsingPickPlacePickup(const moveit_msgs::action::Pickup::Goal& goal, moveit_msgs::action::Pickup::Result* action_res,
                                plan_execution::ExecutableMotionPlan& plan);
  bool planUsingPickPlacePlace(const moveit_msgs::action::Place::Goal& goal, moveit_msgs::action::Place::Result* action_res,
                               plan_execution::ExecutableMotionPlan& plan);

  void preemptPickupCallback();
  void preemptPlaceCallback();

  void startPickupLookCallback();
  void startPickupExecutionCallback();

  void startPlaceLookCallback();
  void startPlaceExecutionCallback();

  void setPickupState(MoveGroupState state);
  void setPlaceState(MoveGroupState state);

  void fillGrasps(moveit_msgs::action::Pickup::Goal& goal);

  std::shared_ptr<pick_place::PickPlace> pick_place_;

  std::shared_ptr<rclcpp_action::Server<moveit_msgs::action::Pickup>> pickup_action_server_;
  moveit_msgs::action::PickupFeedback pickup_feedback_;

  std::unique_ptr<rclcpp_action::Server<moveit_msgs::action::Place> > place_action_server_;
  moveit_msgs::action::Place::Feedback place_feedback_;

  std::unique_ptr<moveit_msgs::msg::AttachedCollisionObject> diff_attached_object_;

  MoveGroupState pickup_state_;
  MoveGroupState place_state_;

  rclcpp::Client<moveit_msgs::srv::GraspPlanning>::SharedPtr grasp_planning_service_;
};
}

#endif
