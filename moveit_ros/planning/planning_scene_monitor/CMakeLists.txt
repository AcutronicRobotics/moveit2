set(MOVEIT_LIB_NAME moveit_planning_scene_monitor)

add_library(${MOVEIT_LIB_NAME} SHARED
  src/planning_scene_monitor.cpp
  src/current_state_monitor.cpp
  src/trajectory_monitor.cpp
)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
ament_target_dependencies(${MOVEIT_LIB_NAME}
  moveit_collision_plugin_loader
  # moveit_occupancy_map_monitor
  moveit_ros_perception
  message_filters
  urdf
  pluginlib
  rclcpp
  Boost
  moveit_msgs
)
target_link_libraries(${MOVEIT_LIB_NAME}
  moveit_robot_model_loader
)

add_executable(demo_scene demos/demo_scene.cpp)
ament_target_dependencies(demo_scene
  rclcpp
  ${MOVEIT_LIB_NAME}
  Boost
  moveit_msgs
  urdf
  message_filters
  pluginlib)

install(TARGETS ${MOVEIT_LIB_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)
