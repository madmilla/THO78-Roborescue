# Install script for directory: /home/owen/pcl/src/pcl-pcl-1.7.2

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_common")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl" TYPE FILE FILES "/home/owen/pcl/src/pcl-pcl-1.7.2/include/pcl/pcl_config.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pclconfig")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl-1.7" TYPE FILE FILES
    "/home/owen/pcl/src/pcl-pcl-1.7.2/PCLConfig.cmake"
    "/home/owen/pcl/src/pcl-pcl-1.7.2/PCLConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/common/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/io/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/kdtree/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/search/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/sample_consensus/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/filters/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/features/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/registration/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/recognition/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/geometry/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/segmentation/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/visualization/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/surface/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/keypoints/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/tracking/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/apps/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/people/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/outofcore/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/test/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/tools/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/examples/cmake_install.cmake")
  include("/home/owen/pcl/src/pcl-pcl-1.7.2/doc/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/owen/pcl/src/pcl-pcl-1.7.2/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
