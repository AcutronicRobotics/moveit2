cmake_minimum_required(VERSION 3.10.2)
project(moveit_ros_move_group)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Boost REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)


include_directories(include)
include_directories(${rclcpp_INCLUDE_DIRS}
                    ${Boost_INCLUDE_DIRS}
                    ${moveit_core_INCLUDE_DIRS})

add_library(moveit_move_group_capabilities_base
  # src/move_group_context.cpp
  src/move_group_capability.cpp
  )
set_target_properties(moveit_move_group_capabilities_base PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")

# add_executable(move_group src/move_group.cpp)

# add_executable(list_move_group_capabilities src/list_capabilities.cpp)

add_library(moveit_move_group_default_capabilities
  # src/default_capabilities/move_action_capability.cpp
  # src/default_capabilities/plan_service_capability.cpp
  # src/default_capabilities/execute_trajectory_action_capability.cpp
  src/default_capabilities/query_planners_service_capability.cpp
  # src/default_capabilities/kinematics_service_capability.cpp
  # src/default_capabilities/state_validation_service_capability.cpp
  # src/default_capabilities/cartesian_path_service_capability.cpp
  # src/default_capabilities/get_planning_scene_service_capability.cpp
  # src/default_capabilities/apply_planning_scene_service_capability.cpp
  # src/default_capabilities/clear_octomap_service_capability.cpp
  )
# set_target_properties(moveit_move_group_default_capabilities PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")

ament_target_dependencies(moveit_move_group_capabilities_base
  rclcpp
  Boost
  moveit_core)
# target_link_libraries(move_group moveit_move_group_capabilities_base ${rclcpp_LIBRARIES} ${Boost_LIBRARIES})
ament_target_dependencies(moveit_move_group_default_capabilities moveit_move_group_capabilities_base
  rclcpp
  Boost)
# target_link_libraries(list_move_group_capabilities ${rclcpp_LIBRARIES} ${Boost_LIBRARIES})

# install(TARGETS move_group list_move_group_capabilities moveit_move_group_capabilities_base moveit_move_group_default_capabilities
#   ARCHIVE DESTINATION lib
#   LIBRARY DESTINATION lib
#   RUNTIME DESTINATION bin)
#TODO (anasarrak): Rever back for the install that is above
install(TARGETS moveit_move_group_capabilities_base
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

install(PROGRAMS
  scripts/load_map scripts/save_map DESTINATION
  lib/${PROJECT_NAME})

install(FILES
  default_capabilities_plugin_description.xml
  DESTINATION share/${PROJECT_NAME})

#TODO (anasarrak): Update the testing once everything is ported to ros2
if(BUILD_TESTING)
  # find_package(rostest REQUIRED)
  # this test is flaky
  # add_rostest(test/test_cancel_before_plan_execution.test)
  find_package(ament_cmake_xmllint REQUIRED)
  find_package(ament_cmake_lint_cmake REQUIRED)
  ament_lint_cmake()
endif()

ament_export_include_directories(include)
ament_export_libraries(moveit_move_group_capabilities_base)
ament_export_dependencies(moveit_core)
ament_export_dependencies(moveit_ros_planning)
ament_export_dependencies(tf2_geometry_msgs)

ament_package()
