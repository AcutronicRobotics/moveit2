cmake_minimum_required(VERSION 3.5)
project(moveit_ros_control_interface)

add_compile_options(-std=c++14)

find_package(moveit_core REQUIRED)
find_package(moveit_simple_controller_manager REQUIRED)
find_package(pluginlib REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(controller_manager_msgs REQUIRED)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system thread)

# support indigo's ros_control - This can be removed upon EOL indigo
if("${controller_manager_msgs_VERSION}" VERSION_LESS "0.10.0")
  add_definitions(-DMOVEIT_ROS_CONTROL_INTERFACE_OLD_ROS_CONTROL)
endif()

include_directories(include ${Boost_INCLUDE_DIRS} ${rclcpp_INCLUDE_DIRS})

add_library(${PROJECT_NAME}_plugin
  src/controller_manager_plugin.cpp
)
set_target_properties(${PROJECT_NAME}_plugin PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${PROJECT_NAME}_plugin
  ${rclcpp_LIBRARIES} ${Boost_LIBRARIES}
)

add_library(${PROJECT_NAME}_trajectory_plugin
  src/joint_trajectory_controller_plugin.cpp
)
set_target_properties(${PROJECT_NAME}_trajectory_plugin PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${PROJECT_NAME}_trajectory_plugin
  ${rclcpp_LIBRARIES} ${Boost_LIBRARIES}
)


#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}_plugin ${PROJECT_NAME}_trajectory_plugin
ARCHIVE DESTINATION lib
LIBRARY DESTINATION lib
RUNTIME DESTINATION lib/${PROJECT_NAME}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME}
)
install(FILES moveit_core_plugins.xml moveit_ros_control_interface_plugins.xml
  DESTINATION share/${PROJECT_NAME}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_canopen_master.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
