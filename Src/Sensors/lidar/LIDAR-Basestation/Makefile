CPP = g++
CPPFLAGS = -std=c++0x -O3 -c -lpthread

PROGRAMS=UDPServer
all: $(PROGRAMS)

clean:
	rm *.o $(PROGRAMS) &> /dev/null || true
	
UDPServer: PracticalSocket.o UDP_Server.o
	$(CPP) -o $@ PracticalSocket.o UDP_Server.o -lpthread -I../../../../Deps/incl/mavlink

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $<

UDP_Server.o: UDP_Server.cpp ../../../../Deps/incl/mavlink/roborescueV1/mavlink.h

PracticalSocket.o: PracticalSocket.h PracticalSocket.cpp
