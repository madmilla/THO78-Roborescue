SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
LIBS = LibSerial.a
LOC = ../Dependencies/Serial/

export TARGET = windows

ifeq ($(TARGET),windows)
	LIBS += -lws2_32
endif
ifeq ($(TARGET),linux)
	LIBS += -lpthread
endif

Main: $(OBJS)
	$(MAKE) -C $(LOC)
	g++ -std=gnu++11 -I../Dependencies/MAVLink/ardupilotmega $^ $(LOC)/$(LIBS) -o $@ -pthread

%.o : %.cpp
	g++ -c -std=gnu++11 $^ -o $@
