# Install script for directory: /home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/CMakeFiles/CMakeRelink.dir/libpcl_octree.so.1.7.2"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/CMakeFiles/CMakeRelink.dir/libpcl_octree.so.1.7"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/CMakeFiles/CMakeRelink.dir/libpcl_octree.so"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/pcl_octree-1.7.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/octree" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/boost.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_base.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_container.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_impl.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_nodes.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_key.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_density.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_occupancy.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_singlepoint.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_pointvector.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_changedetector.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_voxelcentroid.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_iterator.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_search.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree2buf_base.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_adjacency.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_adjacency_container.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/octree/impl" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_base.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_pointcloud.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree2buf_base.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_iterator.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_search.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_pointcloud_voxelcentroid.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_pointcloud_adjacency.hpp"
    )
endif()

