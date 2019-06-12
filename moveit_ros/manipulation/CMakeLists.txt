cmake_minimum_required(VERSION 3.10.2)
project(moveit_ros_manipulation)

add_compile_options(-std=c++14)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(ament_cmake REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(moveit_ros_move_group REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED thread system filesystem date_time program_options)

# pluginlib_export_plugin_description_file("pick_place/cfg/PickPlaceDynamicReconfigure.cfg")
pluginlib_export_plugin_description_file(moveit_ros_move_group pick_place_capability_plugin_description.xml)

include_directories(pick_place/include)
include_directories(move_group_pick_place_capability/include)

include_directories(${rclcpp_INCLUDE_DIRS}
                    ${Boost_INCLUDE_DIRS}
                    ${moveit_core_INCLUDE_DIRS})
include_directories(SYSTEM
                    ${EIGEN3_INCLUDE_DIRS})

add_subdirectory(pick_place)
add_subdirectory(move_group_pick_place_capability)

install(FILES
  pick_place_capability_plugin_description.xml
  DESTINATION share/${PROJECT_NAME})

ament_export_include_directories(include)
ament_export_libraries(moveit_pick_place_planner)
ament_export_dependencies(moveit_core)
ament_export_dependencies(moveit_msgs)
ament_export_dependencies(moveit_ros_planning)
ament_package()
