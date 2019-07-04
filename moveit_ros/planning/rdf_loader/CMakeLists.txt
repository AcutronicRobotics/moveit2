set(MOVEIT_LIB_NAME moveit_rdf_loader)

add_library(${MOVEIT_LIB_NAME} SHARED src/rdf_loader.cpp)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${MOVEIT_LIB_NAME}
  ${Boost_LIBRARIES}
  ${srdfdom_LIBRARIES}
  ${urdf_LIBRARIES}
  ${rclcpp_LIBRARIES}
  ${pluginlib_LIBRARIES}
  ${moveit_core_LIBRARIES}
)

install(TARGETS ${MOVEIT_LIB_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)
