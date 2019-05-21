<img src="https://github.com/AcutronicRobotics/moveit2/raw/master/.logo/official/moveit2_logo-black.png" alt="MoveIt 2 Logo" width="200"/>

[![Build Status](https://travis-ci.org/AcutronicRobotics/moveit2.svg?branch=master)](https://travis-ci.org/AcutronicRobotics/moveit2)

The MoveIt! Motion Planning Framework **for ROS 2.0**

- [Milestones](#milestones)
- [Progress](#progress)
- [Install and test MoveIt 2](#install-and-test-moveit-2)
- [Continuous Integration](#continuous-integration)
- [ROS 2 Buildfarm](#ros-2-buildfarm)

## Milestones

0. [Official announcement, commitment from Acutronic Robotics to allocate PMs and fund PickNik](https://acutronicrobotics.com/news/ros-2-moveit-robotic-motion-planning/)
1. [Why MoveIt 2 and approach](https://acutronicrobotics.com/news/moveit-2-planning-framework-why/)
2. [Porting and understanding `moveit_core`](https://discourse.ros.org/t/the-moveit-2-journey-part-1-porting-and-understanding-moveit-core/8718)

## Progress

<details><summary>Install instructions (DEPRECATED, see below)</summary>

- [x] Install instructions
  - [x] [Ubuntu 18.04](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/ubuntu)
  - [x] [OS X 10.14](https://acutronicrobotics.com/docs/products/robots/mara/moveit2/install/osx)

</details>

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

- [ ] New features in ROS 2.0
  - [ ] Migrate plugin architecture to ROS2 nodelets
</details>

<details><summary>Documentation (<b>not started</b>) </summary>

- [ ] Documentation
  - [ ] Tutorials for MoveIt2
  - [ ] Create tutorial on using ros1/ros2 bridge to support ros1 hardware drivers
  - [ ] Move install instructions to moveit.ros.org
  - [ ] 
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

## Install and test MoveIt 2

Note that moveit2 is a work in progress. Limited effort has been allocated to provide instructions on how to reproduce the available work.

<details><summary>Install and test options</summary>

### From sources

#### Ubuntu 18.04

##### Install  ros2 dashing pre-release 

Follow [this](https://discourse.ros.org/t/ros-2-dashing-diademata-call-for-testing-and-package-releases/8819) to install ros2 dashing pre-release 

**NOTE**: Remove tf2 if you installed it from sources
```
sudo apt-get purge ros-dashing-tf2*
```

Install additional dependencies
```bash
sudo apt-get install python-vcstool python3-colcon-*
```

##### Compile moveit2 and dependencies:

```bash
mkdir -p ~/moveit2_ws/src
cd ~/moveit2_ws/src
git clone https://github.com/AcutronicRobotics/moveit2 -b master_compile
cd ~/moveit2_ws
vcs import src < src/moveit2/moveit2.repos
colcon build --merge-install --cmake-args -DBUILD_TESTING=FALSE
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
git clone -q -b ros2 --depth=1 https://github.com/acutronicrobotics/moveit_ci.git .moveit_ci
export MOVEIT_CI_TRAVIS_TIMEOUT=85  # Travis grants us 90 min, but we add a safety margin of 5 min
export ROS_DISTRO=crystal
export ROS_REPO=acutronicrobotics
export UPSTREAM_WORKSPACE=moveit.rosinstall
export TEST_BLACKLIST="moveit_ros_perception tf2_ros"  # mesh_filter_test fails due to broken Mesa OpenGL
export CXXFLAGS="-Wall -Wextra -Wwrite-strings -Wunreachable-code -Wpointer-arith -Wredundant-decls -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-unused-function"
.moveit_ci/travis.sh
```

#### Using the CI infrastructure in OS X
TODO

### Using a Docker container (**DEPRECATED**)
An attempt to provide an environment whereto build the existing moveit2 repository is available at https://github.com/AcutronicRobotics/moveit2/tree/local-build/.docker/local-build.

```bash
# from https://github.com/AcutronicRobotics/moveit2/tree/local-build/.docker/local-build
# Build it
docker build -t local-build --build-arg=<branch> .
# or docker build -t local-build .

# Run it
docker run -it local-build
# inside of the container, compile the moveit2 code
colcon build --merge-install #Inside of the docker container
```

</details>

## Continuous Integration
[![Build Status](https://travis-ci.org/AcutronicRobotics/moveit2.svg?branch=master)](https://travis-ci.org/AcutronicRobotics/moveit2)

Refer to https://github.com/AcutronicRobotics/moveit_ci. Docker containers (containing the appropriate ROS 2 release with the right dependencies) are created for the purpose of CI and available at https://cloud.docker.com/u/acutronicrobotics/repository/docker/acutronicrobotics/moveit2.

## ROS 2 Buildfarm
Releases of MoveIt 2 aren't planned for now.
