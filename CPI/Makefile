#Makefile for CPI 
CC = g++
CFLAGS=
LDFLAGS=-std=gnu++11
SOURCES= Lidar.cpp RALCPEncoder.cpp Rosbee.cpp UDPSocket.cpp UDPServer.cpp Main.cpp
OBJECTS= $(SOURCES:.cpp=.o)
LIBS = -lmingw32 -lSDLmain -lSDL
EXECUTABLE= CPI

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(LDFLAGS) $< -o $@ $(LIBS)

clean:
	rm *o $(EXECUTABLE)