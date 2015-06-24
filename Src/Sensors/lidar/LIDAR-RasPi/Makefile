#the name of the output file (withoud .exe)

PROG = main
# the needed cpp files (withoud .cpp)
MODULES :=  Circle Line PointCloud shapedetector Lidar LidarController UDPClient CPIConnector main

# the deps directory
DEPS_DIR_WIN:= ..\..\..\..\Deps
DEPS_DIR_LINUX:= ../../../../Deps

HEADER := $(patsubst %,%.h,$(MODULES))

OBJECTS := $(patsubst %,%.o,$(MODULES))


ifeq ($(OS),Windows_NT)
	gcc = g++
	LINKFLAGS = -L$(DEPS_DIR_WIN)\lib\rplidar\windows -lrplidar -L$(DEPS_DIR_WIN)\lib\opencv\Windows  -lopencv_core2410 -lopencv_highgui2410 -lopencv_imgproc2410
	rm = rm -f
	TARGET := $(PROG).exe
	CFLAGS = -std=c++11 -I$(DEPS_DIR_WIN)\incl\rplidar -I$(DEPS_DIR_WIN)\incl\opencv -g

else
	ARCH := $(shell getconf LONG_BIT)
	CPP_FLAGS_32 := $(DEPS_DIR_LINUX)/lib/opencv/Linux/x86
	CPP_FLAGS_64 := $(DEPS_DIR_LINUX)/lib/opencv/Linux/x64
	LINKFLAGS := -L$(DEPS_DIR_LINUX)/lib/rplidar/linux -lrplidar -L$(CPP_FLAGS_$(ARCH)) -lopencv_core -lopencv_highgui -lopencv_imgproc -Wl,-rpath=$(CPP_FLAGS_$(ARCH))
	gcc := /usr/bin/g++
	CFLAGS = -std=c++11 -I$(DEPS_DIR_LINUX)/incl/rplidar -I$(DEPS_DIR_LINUX)/incl/mavlink -lstdc++ -lpthread -lrt -I$(DEPS_DIR_LINUX)/incl/opencv -I$(DEPS_DIR_LINUX)/incl/Donahoo
	rm := rm -f
	TARGET := $(PROG)
endif
.PHONY: build clean

build:	$(TARGET)

clean:
	$(rm) $(TARGET) $(OBJECTS)

$(OBJECTS): %.o : $(HEADERS) %.cpp
	$(gcc) -c  -o  $@  $< $(CFLAGS)
$(TARGET): $(OBJECTS)
	$(gcc)  $(OBJECTS) -o $@ $(LINKFLAGS) $(CFLAGS)
