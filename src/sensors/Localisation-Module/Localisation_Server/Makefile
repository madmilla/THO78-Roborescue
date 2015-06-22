DEPS_INCL_DIR = ../../../../deps/incl/

ARUCO_DIR = $(DEPS_INCL_DIR)aruco/
MAVLINK_DIR = $(DEPS_INCL_DIR)mavlink/common/
PX4FLOW_DIR = ../../../sensors/PX4Flow/
CIMG_DIR = $(DEPS_INCL_DIR)CImg/

LFLAGS = -I $(ARUCO_DIR) -I $(MAVLINK_DIR) -I $(PX4FLOW_DIR) -I $(CIMG_DIR)

MODULES = $(PX4FLOW_DIR)PX4FlowWrapper
HEADERS = aruco.h mavlink.h CImg.h
PROJECT = LocalisationModule

HEADERS += $(patsubst %,%.h,$(MODULES))
OBJECTS += $(patsubst %,%.o,$(MODULES) $(PROJECT))
SOURCES += $(patsubst %,%.cpp,$(MODULES) $(PROJECT))

OPENCVFLAGS = `pkg-config --cflags --libs opencv`

OBJ_FILES = $(HEADERS:.h=.o)
FLAGS = -std=c++11 -lX11 -lboost_system -lpthread
TARGET = linux

.PHONY: all

$(TARGET): $(OBJECTS) $(HEADERS)
	$(info Building target)
	g++ $(FLAGS) -o $@ $(OBJECTS) $(HEADERS) $(LFLAGS)
	
all: $(TARGET)
	
%.o : %.cpp
	$(info Building $@)
	g++ $(FLAGS) -c -o $@ $< $(LFLAGS)
