CPP = g++
CPPFLAGS = -std=c++0x -O3 -c -lpthread

PROGRAMS=UDPClient
all: $(PROGRAMS)

clean:
	rm *.o $(PROGRAMS) &> /dev/null || true
	
UDPClient: main.o PracticalSocket.o UDPServer.o CPIConnector.o
	$(CPP) -o $@ PracticalSocket.o main.o UDPServer.o -lpthread  CPIConnector.o

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $<

main.o: main.cpp UDPServer.h CPIConnector.h ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h
PracticalSocket.o: PracticalSocket.h PracticalSocket.cpp
UDPServer.o: UDPServer.h UDPServer.cpp PracticalSocket.h ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h SocketListener.h
CPIConnector.o: CPIConnector.h CPIConnector.cpp ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h SocketListener.h

