CPP = g++
CPPFLAGS = -std=c++0x -O3 -c -lpthread

PROGRAMS=UDPClient
all: $(PROGRAMS)

clean:
	rm *.o $(PROGRAMS) &> /dev/null || true
	
UDPClient: main.o PracticalSocket.o UDPClient.o CPIConnector.o
	$(CPP) -o $@ PracticalSocket.o main.o UDPClient.o -lpthread  CPIConnector.o

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $<

main.o: main.cpp UDPClient.h CPIConnector.h ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h
PracticalSocket.o: PracticalSocket.h PracticalSocket.cpp
UDPClient.o: UDPClient.h UDPClient.cpp PracticalSocket.h ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h BaseLidar.h
CPIConnector.o: CPIConnector.h CPIConnector.cpp ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h BaseLidar.h

