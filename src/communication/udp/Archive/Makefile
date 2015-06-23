SRC = RALCPEncoder.cpp Rosbee.cpp Lidar.cpp UDPServer.cpp UDPSocket.cpp main.cpp RobotManager.cpp Windows-udp/Client/client.cpp ../../../deps/incl/communication/udp/practicalsocket.cpp UDPRobot.cpp
HEADERS = $(SRC:.cpp:.h) Socket.h Connection.h CPIBoundaryObject.h mingw.thread.h MessageQueue.h RobotManager.h
OBJ = $(SRC:.cpp=.o)
EXEC = Udpserver
CC = g++
LDFLAGS =
LIBS = ws2_32
CFLAGS = -std=c++11 -DWIN32


ifeq ($(shell uname),SunOS)
  LIBS = -lsocket -lnsl
endif

.phony: clean run rebuild test client
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
client:
	$(CC) -c $(CFLAGS) Windows-UDP/Client/client.cpp -o client.o

test:
	make clean
	make all
	make client
	cp *.o ../../tests/auto/UDPCommunication-test
