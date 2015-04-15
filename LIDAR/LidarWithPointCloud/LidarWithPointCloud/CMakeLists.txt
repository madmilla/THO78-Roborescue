project(LidarWithPointCloud)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

set(HEADER_FILES ${include}/*.h)

add_executable(${PROJECT_NAME} ${SRC_LIST})

if (WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/rplidar_driver.lib)
endif (WIN32)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/rplidar_driver.a)
endif (UNIX)
