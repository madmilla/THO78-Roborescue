DEPS_INCL_DIR = ../../../../deps/incl/

ARUCO_DIR = $(DEPS_INCL_DIR)aruco/
MAVLINK_DIR = $(DEPS_INCL_DIR)mavlink/
MAVLINK_EXCHANGER_DIR = ../../../communication/MavlinkExchanger/
SERIALPORT_DIR = ../../../communication/SerialPort/
PX4FLOW_DIR = ../../../sensors/PX4Flow/
CIMG_DIR = $(DEPS_INCL_DIR)CImg/

LFLAGS = -I $(ARUCO_DIR) -I $(MAVLINK_DIR) -I $(PX4FLOW_DIR) -I $(CIMG_DIR) -I $(MAVLINK_EXCHANGER_DIR) -I $(SERIALPORT_DIR)

MODULES = $(PX4FLOW_DIR)PX4FlowWrapper $(MAVLINK_EXCHANGER_DIR)MAVLinkExchanger $(MAVLINK_EXCHANGER_DIR)PrioritisedMAVLinkMessage $(SERIALPORT_DIR)SerialPort TCPServer ARInterface
ARUCO_HEADERS = $(wildcard $(ARUCO_DIR)*.h)
HEADERS = aruco.h mavlink.h CImg.h
PROJECT = LocalisationModule

HEADERS += $(patsubst %,%.h,$(MODULES))
OBJECTS += $(patsubst %,%.o,$(MODULES) $(PROJECT))
SOURCES += $(patsubst %,%.cpp,$(MODULES) $(PROJECT))

OPENCVFLAGS = `pkg-config --cflags --libs opencv`

OBJ_FILES = $(ARUCO_HEADERS:.h=.o)
FLAGS = -std=c++11 -lX11 -lboost_system -lpthread $(OPENCVFLAGS)
TARGET = linux

.PHONY: all

$(TARGET): $(OBJECTS) $(OBJ_FILES) 
	$(info Building target)
	g++-4.9 $(FLAGS) -o $@ $(OBJECTS) $(OBJ_FILES) $(LFLAGS)
	
all: $(TARGET)
	
%.o : %.cpp
	$(info Building $@)
	g++-4.9 $(FLAGS) -c -o $@ $< $(LFLAGS)
