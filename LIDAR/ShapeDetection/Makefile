PROJECT := main

MODULES := shapedetector

CFLAGS := -std=c++11



ARCH := $(shell getconf LONG_BIT)

CPP_FLAGS_32 := ./../../deps/libs/Linux/x86
CPP_FLAGS_64 := ./../../deps/libs/Linux/x64




LINKFLAGS := -L$(CPP_FLAGS_$(ARCH)) -lopencv_core -lopencv_highgui -lopencv_imgproc -Wl,-rpath=$(CPP_FLAGS_$(ARCH))



gcc := /usr/bin/g++

ln := /usr/bin/g++

rm := rm -f



.PHONY: build clean



TARGET := $(PROJECT)

HEADER := $(patsubst %,%.h,$(MODULES))

OBJECTS := $(PROJECT).o $(patsubst %,%.o,$(MODULES))



build: $(TARGET) 


clean:

	$(rm) $(TARGET) $(OBJECTS)



$(TARGET): $(OBJECTS)

	$(ln) -o $@ $(OBJECTS) $(LINKFLAGS)



$(OBJECTS): %.o : $(HEADERS) %.cpp

	$(gcc) -c -o $@ $< $(CFLAGS)
