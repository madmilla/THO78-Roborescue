SRC = RALCPEncoder.cpp Rosbee.cpp UDPServer.cpp UDPSocket.cpp main.cpp
HEADERS = $(SRC:.cpp:.hpp) Socket.hpp Connection.hpp CPIBoundaryObject.hpp mingw.thread.h
OBJ = $(SRC:.cpp=.o)
EXEC = Udpserver
CC = g++
LDFLAGS =
LIBS = ws2_32
CFLAGS = -std=c++11

.phony: clean run rebuild
all: $(SRC) $(EXEC)

$(EXEC):  $(OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ -l $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f *.o *.exe

run:
	make all
	exec $(EXEC).exe

rebuild:
	make clean
	make run