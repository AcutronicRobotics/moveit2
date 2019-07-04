set(MOVEIT_LIB_NAME moveit_ompl_interface)

add_library(${MOVEIT_LIB_NAME} SHARED
  src/ompl_interface.cpp
  src/planning_context_manager.cpp
  src/constraints_library.cpp
  src/model_based_planning_context.cpp
  src/parameterization/model_based_state_space.cpp
  src/parameterization/model_based_state_space_factory.cpp
  src/parameterization/joint_space/joint_model_state_space.cpp
  src/parameterization/joint_space/joint_model_state_space_factory.cpp
  src/parameterization/work_space/pose_model_state_space.cpp
  src/parameterization/work_space/pose_model_state_space_factory.cpp
  src/detail/threadsafe_state_storage.cpp
  src/detail/state_validity_checker.cpp
  src/detail/projection_evaluators.cpp
  src/detail/goal_union.cpp
  src/detail/constrained_sampler.cpp
  src/detail/constrained_valid_state_sampler.cpp
  src/detail/constrained_goal_sampler.cpp
)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
find_package(OpenMP REQUIRED)

ament_target_dependencies(${MOVEIT_LIB_NAME}
  random_numbers
  moveit_core
  moveit_ros_planning
)

target_link_libraries(${MOVEIT_LIB_NAME} 
  ${OMPL_LIBRARIES} 
  ${rclcpp_LIBRARIES} 
  ${Boost_LIBRARIES}
)
  
include_directories(${moveit_core_INCLUDE_DIRS})
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES LINK_FLAGS "${OpenMP_CXX_FLAGS}")

# add_executable(moveit_ompl_planner src/ompl_planner.cpp)
# target_link_libraries(moveit_ompl_planner
#   ${MOVEIT_LIB_NAME}
#   ${moveit_msgs_LIBRARIES}
#   ${moveit_ros_planning_LIBRARIES}
#   ${tf2_ros_LIBRARIES}
# )

# set_target_properties(moveit_ompl_planner PROPERTIES LINK_FLAGS "${OpenMP_CXX_FLAGS}")

# TODO (anasarrak)
# add_executable(moveit_generate_state_database src/generate_state_database.cpp)
# target_link_libraries(moveit_generate_state_database ${MOVEIT_LIB_NAME})
# set_target_properties(moveit_generate_state_database PROPERTIES LINK_FLAGS "${OpenMP_CXX_FLAGS}")
# set_target_properties(moveit_generate_state_database PROPERTIES OUTPUT_NAME "generate_state_database")

add_library(moveit_ompl_planner_plugin SHARED src/ompl_planner_manager.cpp)
set_target_properties(moveit_ompl_planner_plugin PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")
target_link_libraries(moveit_ompl_planner_plugin
  ${MOVEIT_LIB_NAME}
  ${rclcpp_LIBRARIES}
  ${Boost_LIBRARIES}
  ${moveit_ros_planning_LIBRARIES}
)

install(TARGETS ${MOVEIT_LIB_NAME} moveit_ompl_interface moveit_ompl_planner_plugin #moveit_ompl_planner moveit_generate_state_database
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/ DESTINATION include)

# if(BUILD_TESTING)
#   find_package(moveit_resources REQUIRED)
#   include_directories(${moveit_resources_INCLUDE_DIRS})
#
#   catkin_add_gtest(test_state_space test/test_state_space.cpp)
#   target_link_libraries(test_state_space ${MOVEIT_LIB_NAME} ${OMPL_LIBRARIES} ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#   set_target_properties(test_state_space PROPERTIES LINK_FLAGS "${OpenMP_CXX_FLAGS}")
# endif()
