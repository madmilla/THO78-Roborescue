#the name of the output file (withoud .exe)

PROG = main
# the needed cpp files (withoud .cpp)
MODULES := PointCloud Lidar LidarController main

# the deps directory
DEPS_DIR_WIN:= ..\..\deps
DEPS_DIR_LINUX:= ..\..\deps

HEADER := $(patsubst %,%.h,$(MODULES))

OBJECTS := $(patsubst %,%.o,$(MODULES))


ifeq ($(OS),Windows_NT)
	gcc = g++
	LINKFLAGS = -L$(DEPS_DIR_WIN)\lib\rplidar\windows
	rm = rm -f
	TARGET := $(PROG).exe
	CFLAGS = -std=c++11   -I$(DEPS_DIR_WIN)\incl\rplidar

else
	LINKFLAGS := -Lliba -lrplidar
	gcc := /usr/bin/g++
	CFLAGS = -std=c++11   -I$(DEPS_DIR_LINUX) -lstdc++ -lpthread -lrt
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

