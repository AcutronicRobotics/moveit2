set(MOVEIT_LIB_NAME moveit_trajectory_execution_manager)

add_library(${MOVEIT_LIB_NAME} SHARED src/trajectory_execution_manager.cpp)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
ament_target_dependencies(${MOVEIT_LIB_NAME}
  moveit_planning_scene
  moveit_planning_scene_monitor 
  moveit_robot_model_loader
  moveit_robot_state
  rclcpp
  Boost
  tinyxml_vendor
  pluginlib
)
target_link_libraries(${MOVEIT_LIB_NAME}
  moveit_planning_scene_monitor   
  ${moveit_robot_state_LIBRARIES}
  ${moveit_planning_scene_LIBRARIES}  
)

install(TARGETS ${MOVEIT_LIB_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)
if(BUILD_TESTING)
  add_library(test_controller_manager_plugin SHARED test/test_moveit_controller_manager_plugin.cpp)
  set_target_properties(test_controller_manager_plugin PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")

  target_link_libraries(test_controller_manager_plugin
    ${MOVEIT_LIB_NAME}
    ${rclcpp_LIBRARIES}
  )

  if(WIN32)
	  # set(append_library_dirs "$<TARGET_FILE_DIR:${PROJECT_NAME}>;$<TARGET_FILE_DIR:${PROJECT_NAME}_TestPlugins1>")
	else()
	  set(append_library_dirs "${CMAKE_CURRENT_BINARY_DIR};${CMAKE_CURRENT_BINARY_DIR}/../robot_model_loader;${CMAKE_CURRENT_BINARY_DIR}/../planning_scene_monitor;${CMAKE_CURRENT_BINARY_DIR}/../rdf_loader")
	endif()

  find_library(moveit_ros_perception REQUIRED)

  add_executable(test_controller_manage_subcriber test/test_subscriber.cpp)
  target_link_libraries(test_controller_manage_subcriber ${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES})
  add_executable(test_controller_manager_publisher test/test_publisher.cpp)
  target_link_libraries(test_controller_manager_publisher ${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES})

  add_executable(test_publish_dummy_joint_states test/test_publish_dummy_joint_states.cpp)
  target_link_libraries(test_publish_dummy_joint_states ${rclcpp_LIBRARIES} ${sensor_msgs_LIBRARIES} ${std_msgs_LIBRARIES})

  add_executable(test_controller_manager test/test_app.cpp)
  target_include_directories(
    test_controller_manager PUBLIC
    ${moveit_core_INCLUDE_DIRS}
  )
  target_link_libraries(test_controller_manager
    ${MOVEIT_LIB_NAME}
    moveit_trajectory_execution_manager
    moveit_robot_model_loader
    moveit_planning_scene_monitor
    moveit_rdf_loader
    ${moveit_ros_perception_LIBRARIES}
    ${rclcpp_LIBRARIES}
    ${Boost_LIBRARIES}
    ${class_loader_LIBRARIES}
    ${moveit_core_LIBRARIES}
  )

  install(TARGETS test_controller_manager test_controller_manage_subcriber test_controller_manager_publisher test_publish_dummy_joint_states
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/moveit_ros_planning)
endif()
