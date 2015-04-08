# Install script for directory: /home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_search")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/CMakeFiles/CMakeRelink.dir/libpcl_search.so.1.7.2"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/CMakeFiles/CMakeRelink.dir/libpcl_search.so.1.7"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/CMakeFiles/CMakeRelink.dir/libpcl_search.so"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_search")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/pcl_search-1.7.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_search")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/search" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/search.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/kdtree.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/brute_force.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/organized.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/octree.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/flann_search.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/pcl_search.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_search")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/search/impl" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/impl/search.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/impl/kdtree.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/impl/flann_search.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/impl/brute_force.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/search/include/pcl/search/impl/organized.hpp"
    )
endif()

