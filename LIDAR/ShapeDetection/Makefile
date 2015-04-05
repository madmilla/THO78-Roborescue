PROJECT := main
MODULES := shapedetector
CFLAGS := -std=c++11 
LINKFLAGS := -L$(LIB_PATH) -lopencv_core2410d -lopencv_highgui2410d -lopencv_imgproc2410d -lopencv_features2d2410d -lopencv_calib3d2410d
LIB_PATH := ../../deps/lib

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
