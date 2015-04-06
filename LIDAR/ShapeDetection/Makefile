PROJECT := main

MODULES := shapedetector

CFLAGS := -std=c++11 

LINKFLAGS := -L./../../deps/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_features2d -lopencv_calib3d



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
