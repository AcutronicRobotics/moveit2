cmake_minimum_required(VERSION 3.5)
set(MOVEIT_LIB_NAME moveit_robot_model)

add_library(${MOVEIT_LIB_NAME} SHARED
  src/aabb.cpp
  src/fixed_joint_model.cpp
  src/floating_joint_model.cpp
  src/joint_model.cpp
  src/joint_model_group.cpp
  src/link_model.cpp
  src/planar_joint_model.cpp
  src/prismatic_joint_model.cpp
  src/revolute_joint_model.cpp
  src/robot_model.cpp
)
set_target_properties(${MOVEIT_LIB_NAME} PROPERTIES VERSION "${${PROJECT_NAME}_VERSION}")

ament_target_dependencies(${MOVEIT_LIB_NAME}
  urdf
  urdfdom_headers
  visualization_msgs
  moveit_profiler
  moveit_exceptions
  moveit_kinematics_base
	random_numbers)

target_link_libraries(${MOVEIT_LIB_NAME}
		${moveit_profiler_LIBRARIES}
		${moveit_exceptions_LIBRARIES}
		moveit_profiler
		moveit_exceptions
    ${geometric_shapes_LIBRARIES}
)

ament_export_libraries(${MOVEIT_LIB_NAME})
ament_export_include_directories(include)

install(TARGETS ${MOVEIT_LIB_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(moveit_resources REQUIRED)
  include_directories(${moveit_resources_INCLUDE_DIRS})
	find_package(resource_retriever REQUIRED)

	if(WIN32)
	  # set(append_library_dirs "$<TARGET_FILE_DIR:${PROJECT_NAME}>;$<TARGET_FILE_DIR:${PROJECT_NAME}_TestPlugins1>")
	else()
	  set(append_library_dirs "${CMAKE_CURRENT_BINARY_DIR}:${CMAKE_CURRENT_BINARY_DIR}/../utils")
	endif()

  ament_add_gtest(test_moveit_robot_model test/test.cpp
				APPEND_LIBRARY_DIRS "${append_library_dirs}"
	)

	target_include_directories(test_moveit_robot_model PUBLIC
					${Boost_INCLUDE_DIRS}
					${rclcpp_INCLUDE_DIRS}
					${srdfdom_INCLUDE_DIRS}
					${urdfdom_INCLUDE_DIRS}
					${urdf_INCLUDE_DIRS}
					${geometric_shapes_INCLUDE_DIRS}
					${urdfdom_headers_INCLUDE_DIRS}
					${resource_retriever_INCLUDE_DIRS}
	)
	target_link_libraries(test_moveit_robot_model
				${Boost_LIBRARIES}
				${rclcpp_LIBRARIES}
				${MOVEIT_LIB_NAME}
				moveit_test_utils
				moveit_utils
				moveit_profiler
				moveit_exceptions
				${moveit_profiler_LIBRARIES}
				${srdfdom_LIBRARIES}
				${urdfdom_LIBRARIES}
				${urdf_LIBRARIES}
				${geometric_shapes_LIBRARIES}
				resource_retriever::resource_retriever
	)
endif()
