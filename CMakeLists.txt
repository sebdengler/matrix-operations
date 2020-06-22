cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(matrix_operations)

add_executable (matrix_operations src/main.cpp src/matrix.cpp src/vector.cpp)
