cmake_minimum_required(VERSION 3.10.2)
project(_PACKAGE_NAME_)

add_compile_options(-std=c++14)

find_package(ament_cmake REQUIRED)
find_package(moveit_core REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_kdl REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(eigen_conversions REQUIRED)
find_package(LAPACK REQUIRED)

include_directories(${rclcpp_INCLUDE_DIRS} include)

set(IKFAST_LIBRARY_NAME _LIBRARY_NAME_)
add_library(${IKFAST_LIBRARY_NAME} src/_ROBOT_NAME___GROUP_NAME__ikfast_moveit_plugin.cpp)
target_link_libraries(${IKFAST_LIBRARY_NAME} ${rclcpp_LIBRARIES} ${Boost_LIBRARIES} ${LAPACK_LIBRARIES})
# suppress warnings about unused variables in OpenRave's solver code
target_compile_options(${IKFAST_LIBRARY_NAME} PRIVATE -Wno-unused-variable)

install(TARGETS
  ${IKFAST_LIBRARY_NAME}
  LIBRARY DESTINATION lib)

install(
  FILES
  _ROBOT_NAME___GROUP_NAME__moveit_ikfast_plugin_description.xml
  DESTINATION
  share/${PROJECT_NAME}
)

ament_cmake()
