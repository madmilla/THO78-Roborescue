SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
LIBS = LibSerial.a
LOC = ../Dependencies/Serial/

export TARGET = linux

ifeq ($(TARGET),windows)
	LIBS += -lws2_32
endif
ifeq ($(TARGET),linux)
	LIBS += -lpthread
endif

Main: $(OBJS)
	$(MAKE) -C $(LOC)
	g++ -std=gnu++11 -I../Dependencies/MAVLink/ardupilotmega $^ $(LOC)/$(LIBS) -o $@

%.o : %.cpp
	g++ -c -std=gnu++11 $^ -o $@
