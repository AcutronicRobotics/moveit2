set(MOVEIT_LIB_NAME moveit_trajectory_rviz_plugin)

# Header files that need Qt Moc pre-processing for use with Qt signals, etc:
set(HEADERS
  include/moveit/trajectory_rviz_plugin/trajectory_display.hpp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Trajectory Display
add_library(${MOVEIT_LIB_NAME} SHARED
  src/trajectory_display.cpp
  ${HEADERS}
)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${MOVEIT_LIB_NAME}
  moveit_rviz_plugin_render_tools
  moveit_planning_scene_rviz_plugin
  ${QT_LIBRARIES} ${Boost_LIBRARIES}
)

# Plugin Initializer
#[[add_library(${MOVEIT_LIB_NAME} SHARED src/plugin_init.cpp)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(${MOVEIT_LIB_NAME} ${MOVEIT_LIB_NAME}_core ${Boost_LIBRARIES})
]]
install(DIRECTORY include/ DESTINATION include)

install(
  TARGETS ${MOVEIT_LIB_NAME}
  EXPORT ${MOVEIT_LIB_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
