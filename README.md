<img src="https://github.com/AcutronicRobotics/moveit2/raw/master/.logo/official/moveit2_logo-black.png" alt="MoveIt 2 Logo" width="200"/>

The MoveIt! Motion Planning Framework **for ROS 2.0**

- [Milestones](#milestones)
- [Overview of MoveIt!](http://moveit.ros.org)
- [Installation instructions for MoveIt 2](https://github.com/AcutronicRobotics/moveit2#install-and-test-moveit-2)
- [Documentation](http://moveit.ros.org/documentation/)
- [Get Involved](http://moveit.ros.org/documentation/contributing/)

## Milestones

0. [Official announcement, commitment from Acutronic Robotics to allocate PMs and fund PickNik](https://acutronicrobotics.com/news/ros-2-moveit-robotic-motion-planning/)
1. [Why MoveIt 2 and approach](https://acutronicrobotics.com/news/moveit-2-planning-framework-why/)
2. [Porting and understanding moveit_core](https://acutronicrobotics.com/news/moveit-2-planning-framework-why/)
3. [First demonstrator in ROS 2, planning to a joint-space goal](https://acutronicrobotics.com/news/moveit-2-journey-first-demonstrator/)
4. [Sensorless collision detection with ROS 2](https://acutronicrobotics.com/news/ros2-sensorless-collision-detection/)
5. [Announcing MoveIt 2 alpha release](https://acutronicrobotics.com/news/moveit-2-journey-moveit-2-alpha-release/)

### Progress

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

- [ ] Necessary for a Minimal Working Example
  - [x] moveit_core
  - [x] moveit_ros_perception
    - [x] occupancy_map_monitor
  - [x] move_group
  - [x] moveit_ros_planning
    - [x] rdf_loader
    - [x] collision_plugin_loader
    - [x] kinematics_plugin_loader
    - [x] robot_model_loader
    - [x] constraint_sampler_manager_loader
    - [x] planning_request_adapter_plugins
    - [x] planning_pipeline
    - [x] planning_scene_monitor
    - [x] trajectory_execution_manager
    - [x] plan_execution
  - [ ] planning_interface
    - [x] common_planning_interface_objects
    - [x] planning_scene_interface
    - [ ] move_group_interface (_partially_)
    - [x] test
  - [ ] moveit_planner
    - [x] ompl
  - [ ] moveit_kinematics
    - [x] kdl_kinematics_plugin
  - [ ] moveit_plugins
    - [x] moveit_fake_cotroller_manager
    - [x] moveit_simple_controller_manager
</details>

<details><summary>New features in ROS 2.0 (<b>not started</b>)</summary>

- [ ] New features in ROS 2.0 (see [last survey for more insights](https://moveit.ros.org/assets/pdfs/2019/moveit_2019_survey.pdf))
  - [ ] Realtime support
  - [ ] Lifecycle management of the ROS nodes%
  - [ ] Replacing plugins with ROS 2 components
  - [ ] Security support
  - [ ] Improved namespace handling
  - [ ] Windows support
</details>

<details><summary>Documentation (<b>not started</b>)</summary>

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

## Install and Test MoveIt 2

Note that MoveIt 2 is a work in progress. Limited effort has been allocated to provide instructions on how to reproduce the available work.

<details><summary>Install and test options</summary>

### Build From Source

#### Ubuntu 18.04

##### Install  ROS 2 Dashing Diademata

Follow [this](https://index.ros.org/doc/ros2/Installation/Dashing/Linux-Install-Debians/) to install ROS 2 Dashing

##### Compile MoveIt 2 and Dependencies:

Install additional build dependencies:
```bash
sudo apt-get install python-vcstool python3-colcon-common-extensions
```

**Warning:**`--symlink-install` flag is not compatible for now: https://github.com/AcutronicRobotics/moveit2/issues/112, https://github.com/AcutronicRobotics/moveit2/issues/104

Download and build MoveIt2:

```bash
mkdir -p ~/moveit2_ws/src
cd ~/moveit2_ws/src
git clone https://github.com/AcutronicRobotics/moveit2 -b master
cd ..
vcs import src < src/moveit2/moveit2.repos
export ROS_DISTRO=dashing
source /opt/ros/dashing/setup.bash
rosdep update && rosdep install -q -y --from-paths . --ignore-src --rosdistro ${ROS_DISTRO}
colcon build --merge-install
```

### Using a Docker container

```bash
# Host machine
docker run -it ros:dashing
# Inside of the docker image
mkdir -p ~/moveit2_ws/src
cd ~/moveit2_ws/src
git clone https://github.com/AcutronicRobotics/moveit2 -b master
cd ..
vcs import src < src/moveit2/moveit2.repos
apt update
rosdep update && rosdep install -q -y --from-paths . --ignore-src --rosdistro ${ROS_DISTRO} --as-root=apt:false || true
colcon build --merge-install
```


#### OS X 10.14 (**DEPRECATED**)
Refer to [https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/osx](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/osx) (outdated)


### Using the CI infrastructure
Moveit uses a Docker-based CI infrastructure to run tests and validate commits. Such infrastructure adapted for MoveIt 2 is available at https://github.com/acutronicrobotics/moveit_ci.git.

Using the CI infrastructure, one can get access to MoveIt 2 current status and test its capabilities

#### Using the CI infrastructure in Ubuntu
**Note:** You need to have docker installed on your system.

```bash
cd ~ && git clone https://github.com/AcutronicRobotics/moveit2
cd ~/moveit2
git clone -q -b dashing --depth=1 https://github.com/acutronicrobotics/moveit2_ci.git .moveit2_ci
source .travis.linux.env
.moveit2_ci/travis.sh
```

#### Using the CI infrastructure in OS X
TODO

</details>

## Continuous Integration
[![Build Status](https://travis-ci.org/AcutronicRobotics/moveit2.svg?branch=master)](https://travis-ci.org/AcutronicRobotics/moveit2)

## Docker Containers
https://cloud.docker.com/u/acutronicrobotics/repository/docker/acutronicrobotics/moveit2
