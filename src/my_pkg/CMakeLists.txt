cmake_minimum_required(VERSION 3.8)
project(my_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(welcome_node src/simple_welcome_node.cpp)
ament_target_dependencies(welcome_node rclcpp)

install (TARGETS
  welcome_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
