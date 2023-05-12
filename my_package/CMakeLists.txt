cmake_minimum_required(VERSION 3.5)
project(my_package)

find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED COMPONENTS common)

file(GLOB_RECURSE LIBRARY_HDRS "include/my_package/*.h")
file(GLOB_RECURSE LIBRARY_SRCS "src/*.cc")
file(GLOB TEST_SRCS "test/*.cc")

add_library(${PROJECT_NAME} STATIC ${LIBRARY_SRCS} ${LIBRARY_HDRS})
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${EIGEN_INCLUDE_DIR} ${PCL_INCLUDE_DIRS}
         $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION .)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config)
install(EXPORT ${PROJECT_NAME}Config DESTINATION share/${PROJECT_NAME}/cmake)

enable_testing()
find_package(GTest REQUIRED)
foreach(TEST_SRC ${TEST_SRCS})
  get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SRC})
  target_link_libraries(${TEST_NAME} ${PROJECT_NAME} GTest::GTest GTest::Main)
  add_test(${TEST_NAME} ${TEST_NAME})
endforeach()
