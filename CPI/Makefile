#Makefile for CPI 
CC = g++
CFLAGS=
LDFLAGS=-std=c++0x
SOURCES= Lidar.cpp RALCPEncoder.cpp Rosbee.cpp UDPSocket.cpp UDPServer.cpp Main.cpp
OBJECTS= $(SOURCES:.cpp=.o)
LIBS = -pthread 
EXECUTABLE= CPI

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(LDFLAGS) $< -o $@ $(LIBS)

clean:
	rm *o $(EXECUTABLE)