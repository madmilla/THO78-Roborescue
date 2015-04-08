if(NOT EXISTS "/home/owen/pcl/src/pcl-pcl-1.7.2/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"/home/owen/pcl/src/pcl-pcl-1.7.2/install_manifest.txt\"")
endif(NOT EXISTS "/home/owen/pcl/src/pcl-pcl-1.7.2/install_manifest.txt")

file(READ "/home/owen/pcl/src/pcl-pcl-1.7.2/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
    message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
    if(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
        exec_program("/usr/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
            OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
        if(NOT "${rm_retval}" STREQUAL 0)
            message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
        endif(NOT "${rm_retval}" STREQUAL 0)
    else(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
        message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
    endif(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
endforeach(file)

# remove pcl directory in include (removes all files in it!)
message(STATUS "Uninstalling \"/usr/local/include/pcl-1.7\"")
if(EXISTS "/usr/local/include/pcl-1.7")
    exec_program("/usr/bin/cmake"
        ARGS "-E remove_directory \"/usr/local/include/pcl-1.7\""
        OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
        message(FATAL_ERROR
            "Problem when removing \"/usr/local/include/pcl-1.7\"")
    endif(NOT "${rm_retval}" STREQUAL 0)
else(EXISTS "/usr/local/include/pcl-1.7")
    message(STATUS
        "Directory \"/usr/local/include/pcl-1.7\" does not exist.")
endif(EXISTS "/usr/local/include/pcl-1.7")

# remove pcl directory in share (removes all files in it!)
# created by CMakeLists.txt for PCLConfig.cmake
message(STATUS "Uninstalling \"/usr/local/share/pcl-1.7\"")
if(EXISTS "/usr/local/share/pcl-1.7")
    exec_program("/usr/bin/cmake"
        ARGS "-E remove_directory \"/usr/local/share/pcl-1.7\""
        OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
        message(FATAL_ERROR
            "Problem when removing \"/usr/local/share/pcl-1.7\"")
    endif(NOT "${rm_retval}" STREQUAL 0)
else(EXISTS "/usr/local/share/pcl-1.7")
    message(STATUS
        "Directory \"/usr/local/share/pcl-1.7\" does not exist.")
endif(EXISTS "/usr/local/share/pcl-1.7")

# remove pcl directory in share/doc (removes all files in it!)
if(OFF)
  message(STATUS "Uninstalling \"/usr/local/share/doc/pcl-1.7\"")
  if(EXISTS "/usr/local/share/doc/pcl-1.7")
      exec_program("/usr/bin/cmake"
          ARGS "-E remove_directory \"/usr/local/share/doc/pcl-1.7\""
          OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
      if(NOT "${rm_retval}" STREQUAL 0)
          message(FATAL_ERROR
              "Problem when removing \"/usr/local/share/doc/pcl-1.7\"")
      endif(NOT "${rm_retval}" STREQUAL 0)
  else(EXISTS "/usr/local/share/doc/pcl-1.7")
      message(STATUS
          "Directory \"/usr/local/share/doc/pcl-1.7\" does not exist.")
  endif(EXISTS "/usr/local/share/doc/pcl-1.7")
endif()
