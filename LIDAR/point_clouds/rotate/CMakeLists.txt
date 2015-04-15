cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pcl-matrix_transform)

find_package(PCL 1.7 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (rotate main.cpp rotate.cpp rotate.h)
target_link_libraries (rotate ${PCL_LIBRARIES})