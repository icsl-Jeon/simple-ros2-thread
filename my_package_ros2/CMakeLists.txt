cmake_minimum_required(VERSION 3.5)
project(my_package_ros2)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(my_package REQUIRED)

add_library(server src/server/server.cc)
ament_target_dependencies(server rclcpp)
target_include_directories(
  server PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:include>)
target_link_libraries(server my_package)
install(FILES include/${PROJECT_NAME}/server/server.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}/server)

add_executable(server_node src/server/server_node.cc)
target_link_libraries(server_node server)
install(TARGETS server_node DESTINATION lib/${PROJECT_NAME})

enable_testing()
find_package(GTest REQUIRED)

add_executable(server_test test/server_test.cc)
target_link_libraries(server_test server GTest::GTest GTest::Main)
add_test(server_test server_test)

ament_package()
