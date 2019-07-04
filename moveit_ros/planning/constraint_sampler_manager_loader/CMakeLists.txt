set(MOVEIT_LIB_NAME moveit_constraint_sampler_manager_loader)

add_library(${MOVEIT_LIB_NAME} SHARED src/constraint_sampler_manager_loader.cpp)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${MOVEIT_LIB_NAME} 
  ${rclcpp_LIBRARIES}
  moveit_rdf_loader
)

install(TARGETS ${MOVEIT_LIB_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)
