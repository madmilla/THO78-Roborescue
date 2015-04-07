#the name of the output file (withoud .exe)

PROG = main
# the needed cpp files (withoud .cpp)
MODULES := main shapedetector



CFLAGS = -std=c++11 
 
HEADER := $(patsubst %,%.h,$(MODULES  ))

OBJECTS := $(patsubst %,%.o,$(MODULES))

ifeq ($(OS),Windows_NT)
	gcc = g++
	LINKFLAGS = -I"..\..\deps\files\opencv"  -L"..\..\deps\libs\opencv\Windows" -lopencv_core2410 -lopencv_highgui2410 -lopencv_imgproc2410 -Wl,-rpath="..\..\deps\bin"
	rm = del
	TARGET := $(PROG).exe

else
	ARCH := $(shell getconf LONG_BIT)
	CPP_FLAGS_32 := ./../../deps/libs/Linux/x86	
	CPP_FLAGS_64 := ./../../deps/libs/Linux/x64
	LINKFLAGS := -L$(CPP_FLAGS_$(ARCH)) -lopencv_core -lopencv_highgui -lopencv_imgproc -Wl,-rpath=$(CPP_FLAGS_$(ARCH))	
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

