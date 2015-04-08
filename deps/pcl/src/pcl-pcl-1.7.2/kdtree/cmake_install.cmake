# Install script for directory: /home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_kdtree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/CMakeFiles/CMakeRelink.dir/libpcl_kdtree.so.1.7.2"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/CMakeFiles/CMakeRelink.dir/libpcl_kdtree.so.1.7"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/CMakeFiles/CMakeRelink.dir/libpcl_kdtree.so"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_kdtree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/pcl_kdtree-1.7.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_kdtree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/kdtree" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/include/pcl/kdtree/kdtree.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/include/pcl/kdtree/io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/include/pcl/kdtree/flann.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/include/pcl/kdtree/kdtree_flann.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_kdtree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/kdtree/impl" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/include/pcl/kdtree/impl/io.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/kdtree/include/pcl/kdtree/impl/kdtree_flann.hpp"
    )
endif()

