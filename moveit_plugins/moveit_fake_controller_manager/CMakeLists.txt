cmake_minimum_required(VERSION 3.5)
project(moveit_fake_controller_manager)

add_compile_options(-std=c++14)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Boost REQUIRED thread)
find_package(ament_cmake REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include)

include_directories(${Boost_INCLUDE_DIRS} ${rclcpp_INCLUDE_DIRS} ${moveit_ros_planning_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED
   src/moveit_fake_controller_manager.cpp
   src/moveit_fake_controllers.cpp
 )

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  Boost
  moveit_core
  moveit_ros_planning
)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${PROJECT_NAME} ${rclcpp_LIBRARIES} ${Boost_LIBRARIES})

pluginlib_export_plugin_description_file(moveit_core moveit_fake_controller_manager_plugin_description.xml)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)

ament_export_include_directories(include)
ament_export_dependencies(moveit_core)
ament_export_dependencies(moveit_ros_planning)
ament_package()
