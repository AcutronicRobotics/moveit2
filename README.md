<img src="https://github.com/AcutronicRobotics/moveit2/raw/master/.logo/official/moveit2_logo-black.png" alt="MoveIt 2 Logo" width="200"/>

The MoveIt! Motion Planning Framework **for ROS 2.0**

- [Milestones](#milestones)
- [Overview of MoveIt!](http://moveit.ros.org)
- [Installation instructions for MoveIt 2](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install)
  - [Ubuntu 18.04](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/ubuntu)
  - [OS X 10.14](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/osx)
- [Documentation](http://moveit.ros.org/documentation/)
- [Get Involved](http://moveit.ros.org/documentation/contributing/)

## Milestones

0. [Official announcement, commitment from Acutronic Robotics to allocate PMs and fund PickNik](https://acutronicrobotics.com/news/ros-2-moveit-robotic-motion-planning/)
1. [Why MoveIt 2 and approach](https://acutronicrobotics.com/news/moveit-2-planning-framework-why/)

### Progress

- [x] Install instructions
  - [x] [Ubuntu 18.04](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/ubuntu)
  - [x] [OS X 10.14](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/osx)

<details><summary>Update/setup infrastructure for development</summary>

- [x] Upgrade continuous integration for ROS 2.0
  - [x] Simple CI with Travis (Linux and OS X)
  - [x] moveit_ci https://github.com/AcutronicRobotics/moveit_ci/tree/ros2
- [x] Convert all headers and link it to HRIM (contributed by @ibaiape)
- [x] Update/setup infrastructure for development
  - [x] Delete metapackages
  - [x] Upgrade continuous integration for ROS 2.0
  - [x] Refactor/cleanup folder hierarchy
</details>

<details><summary>Dependencies on other packages</summary>

- [x] Dependencies on other packages
  - [x] tf2_kdl https://github.com/ros2/geometry2/pull/90
  - [x] eigen_stl_containers https://github.com/AcutronicRobotics/eigen_stl_containers/tree/ros2
  - [x] geometric_shapes https://github.com/ros-planning/geometric_shapes/pull/96
  - [x] random_numbers https://github.com/ros-planning/random_numbers/pull/12
  - [x] srdfdom (contributed by @anasarrak, @vmayoral and @ahcorde) https://github.com/ros-planning/srdfdom/pull/45
  - [x] urdf_parser_py https://github.com/ros/urdf_parser_py/pull/41
  - [x] Created a ROS 2 version (with package.xml) of urdfdom_headers https://github.com/AcutronicRobotics/urdfdom_headers/tree/ros2
  - [x] octomap https://github.com/AcutronicRobotics/octomap
    - [x]  octomap
    - [ ]  octovis
    - [ ]  dynamicEDT3D
</details>

<details><summary>Convert moveit_core packages to ROS 2.0</summary>

- [x] Convert moveit_core packages to ROS 2.0
  - [x] version
  - [x] macros
  - [x] backtrace
  - [x] exceptions
  - [x] profiler
  - [x] logging
  - [x] background_processing
  - [x] kinematics_base
  - [x] controller_manager
  - [x] sensor_manager
  - [x] robot_model
  - [x] transforms
  - [x] robot_state
  - [x] robot_trajectory
  - [x] collision_detection
  - [x] collision_detection_fcl
  - [x] kinematic_constraints
  - [x] planning_scene
  - [x] constraint_samplers
  - [x] planning_interface
  - [x] planning_request_adapter
  - [x] trajectory_processing
  - [x] distance_field
  - [x] collision_distance_field
  - [x] kinematics_metrics
  - [x] dynamics_solver
  - [x] utils
</details>

<details><summary>Other moveit packages (e.g. moveit_ros, ...)</summary>

- [ ] moveit_ros
    - [x] moveit_ros_planning_interface (*dummy interface for now*)
        - [ ] py_bindings_tools
        - [ ] common_planning_interface_objects
        - [ ] planning_scene_interface
        - [ ] move_group_interface
        - [ ] robot_interface
        - [ ] test
    - [ ] move_group
    - [ ] planning
        - [x] collision_plugin_loader https://github.com/ros-planning/moveit2/pull/69
        - [x] rdf_loader https://github.com/ros-planning/moveit2/pull/71
        - [x] kinematics_plugin_loader https://github.com/ros-planning/moveit2/pull/74
    - [x] moveit_ros_perception
        - [x] occupancy_map_monitor
        - [ ] lazy_free_space_updater
        - [ ] point_containment_filter
        - [ ] pointcloud_octomap_updater
        - [ ] mesh_filter
        - [ ] depth_image_octomap_updater
        - [ ] semantic_world
    - [ ] moveit_ros_manipulation
      - [ ] move_group_pick_place_capability

</details>

<details><summary>Necessary for a Minimal Working Example</summary>

- [ ] Necessary for a Minimal Working Example (This list can vary, they are the initial includes for the *planning_interface/move_group_interface* that is what we need for a **plan** and **execute**)
  - [x] moveit_ros_perception
    - [x] occupancy_map_monitor
  - [ ] move_group
    - [ ] capability_names
  - [ ] planning
    - [x] collision_plugin_loader
    - [x] planning_scene_monitor
      - [x] current_state_monitor
      - [x] planning_scene_monitor
      - [x] trajectory_monitor
    - [ ] trajectory_execution_manager
      - [ ] trajectory_execution_manager
    - [ ] common_planning_interface_objects
      - [ ] common_objects
  - [ ] planning_interface
    - [ ] planning_scene_interface
      - [ ] planning_scene_interface
  - [ ] moveit_ros_manipulation
    - [ ] move_group_pick_place_capability
      - [ ] capability_names.h

</details>

<details><summary>New features in ROS 2.0</summary>

- [ ] New features in ROS 2.0
  - [ ] Migrate plugin architecture to ROS2 nodelets
</details>

<details><summary>Documentation</summary>
- [ ] Documentation
  - [ ] Tutorials for MoveIt2
  - [ ] Create tutorial on using ros1/ros2 bridge to support ros1 hardware drivers
  - [ ] Move install instructions to moveit.ros.org
</details>

<details><summary>Major refactoring and divergence from moveit2 (<b>not started</b>)</summary>

- [ ] Major refactoring and divergence from moveit2
  - [ ] Run ROS2 C++ and python linters
  - [ ] Delete excesses packages that are left over from rosbuild stacks: moveit_runtime, moveit_plugins, moveit_ros
  - [ ] Rename non-package folders:
    - [ ] rename moveit_planners to planners
    - [ ] rename moveit_plugins to controller_interfaces
  - [ ] Restructure folder layout of moveit repo:
    - [ ] flatten moveit_ros folder to root of repo
    - [ ] rename all moveit_ros folders with moveit_ros prefix
  - [ ] Rename major classes
    - [ ] ControllerManagers become ControllerInterfaces
    - [ ] Rename related packages
  - [ ] Merge repos:
    - [ ] moveit 9.6 MB
    - [ ] moveit_task_constructor
    - [ ] moveit_tutorials  28.6 MB
    - [ ] moveit_msgs
    - [ ] moveit_resources  61 MB
    - [ ] moveit_visual_tools
    - [ ] moveit_advanced?
    - [ ] DELETE: moveit_kinematics_tests
  - [ ] Remove large binaries from moveit repo
  - [ ] Add gitlfs?
</details>

## Continuous Integration Status
[![Build Status](https://travis-ci.org/AcutronicRobotics/moveit2.svg?branch=master)](https://travis-ci.org/AcutronicRobotics/moveit2)

## Docker Containers
https://cloud.docker.com/u/acutronicrobotics/repository/docker/acutronicrobotics/moveit2

## ROS Buildfarm
Debian releases of MoveIt2 will not be available during the alpha development stage. Check back May 2019.
