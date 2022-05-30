cmake_minimum_required (VERSION 2.8)

project (RayTracing)
set(CMAKE_CXX_STANDARD 14)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SRC_DIR})
add_executable(RayTracing ${SRC_DIR}/main.cpp)