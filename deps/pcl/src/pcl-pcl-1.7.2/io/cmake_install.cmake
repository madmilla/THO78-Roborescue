# Install script for directory: /home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/CMakeFiles/CMakeRelink.dir/libpcl_io_ply.so.1.7.2"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/CMakeFiles/CMakeRelink.dir/libpcl_io_ply.so.1.7"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/CMakeFiles/CMakeRelink.dir/libpcl_io_ply.so"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/io/ply" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ply/byte_order.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ply/io_operators.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ply/ply.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ply/ply_parser.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/CMakeFiles/CMakeRelink.dir/libpcl_io.so.1.7.2"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/CMakeFiles/CMakeRelink.dir/libpcl_io.so.1.7"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/CMakeFiles/CMakeRelink.dir/libpcl_io.so"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/pcl_io-1.7.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/io" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/boost.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/eigen.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/debayer.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/file_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/lzf.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/lzf_image_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/grabber.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/file_grabber.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/pcd_grabber.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/pcd_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/vtk_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ply_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/tar.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/obj_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ascii_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/ifs_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image_grabber.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/hdl_grabber.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/robot_eye_grabber.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/point_cloud_image_extractors.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/io_exception.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/vtk_lib_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/png_io.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image_metadata_wrapper.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image_rgb24.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image_yuv422.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image_ir.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/image_depth.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/dinast_grabber.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/compression" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/octree_pointcloud_compression.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/color_coding.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/compression_profiles.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/entropy_range_coder.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/point_coding.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/organized_pointcloud_conversion.h"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/libpng_wrapper.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_io")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/io/impl" TYPE FILE FILES
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/impl/pcd_io.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/impl/lzf_image_io.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/impl/synchronized_queue.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/impl/point_cloud_image_extractors.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/impl/entropy_range_coder.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/compression/impl/octree_pointcloud_compression.hpp"
    "/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/include/pcl/io/impl/vtk_lib_io.hpp"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/owen/THO78-Roborescue/deps/pcl/src/pcl-pcl-1.7.2/io/tools/cmake_install.cmake")

endif()

