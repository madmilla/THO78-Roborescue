PROG = main
# the needed cpp files (withoud .cpp)
MODULES := combine_clouds

# the deps directory
DEPS_DIR_WIN:= ..\..\deps
DEPS_DIR_LINUX:= ../../deps
CFLAGS = -std=c++11 
 
HEADER := $(patsubst %,%.h,$(MODULES  ))

OBJECTS := $(patsubst %,%.o,$(MODULES))

ifeq ($(OS),Windows_NT)
	gcc = g++
	LINKFLAGS = -I$(DEPS_DIR_WIN)"\files\opencv"  -L$(DEPS_DIR_WIN)"\libs\opencv\Windows" -lopencv_core2410 -lopencv_highgui2410 -lopencv_imgproc2410 -Wl,-rpath=$(DEPS_DIR_WIN)"\bin"
	rm = del
	TARGET := $(PROG).exe

else
	ARCH := $(shell getconf LONG_BIT)
	CPP_FLAGS_32 := $(DEPS_DIR_LINUX)/libs/linux	
	CPP_FLAGS_64 := $(DEPS_DIR_LINUX)/libs/linux
	LINKFLAGS := -L$(CPP_FLAGS_$(ARCH))-Wl,-rpath=$(CPP_FLAGS_$(ARCH))	
	gcc := /usr/bin/g++
	rm := rm -f
	TARGET := $(PROG)
endif
.PHONY: build clean

build: $(TARGET) 

clean:		
	$(rm) $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(gcc) -o $@ $(OBJECTS) $(LINKFLAGS)

$(OBJECTS): %.o : $(HEADERS) %.cpp
	$(gcc) -c -o $@ $< $(CFLAGS)

