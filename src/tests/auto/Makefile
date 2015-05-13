#This Makefile is used to build one or multiple automatic tests
#
#To add a test do the following:
#1. Add the test name to the .PHONY targets. 
#This should be the name of the directory the test is in and will be the name of the final executable.
#
#2. Create a rule to build the target.
#A rule should be in the form of:
#test-name: test-dir\dependency1.o test-dir\dependency2.o ...etc
#	$(CC) $(CFLAGS) $^ -o $@\$@ $(LDFLAGS)

CC = g++
CFLAGS =  -std=c++11

.PHONY: all clean vb1 vb2 UDPCommunication-test

vb1: vb1\Main.o vb1\Class.o
	$(CC) $(CFLAGS) $^ -o $@\$@ $(LDFLAGS)
	
vb2: vb2\Main.o
	$(CC) $(CFLAGS) $^ -o $@\$@ $(LDFLAGS)
	
UDPCommunication-test: UDPCommunication-test\test.o UDPCommunication-test\client.o UDPCommunication-test\UDPServer.o UDPCommunication-test\UDPSocket.o
	$(CC) $(CFLAGS) $^ -o $@\$@ $(LDFLAGS) -l ws2_32
	exec UDPCommunication-test/UDPCommunication-test.exe 10
	mv *.txt ../../../results

UDPCommunication-test\client.o UDPCommunication-test\UDPServer.o UDPCommunication-test\UDPSocket.o:
	make -C ../../communication/udp test
	

all: vb1 vb2
	
#######Generic rules#######
%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@
	
clean:
	@echo 'Cleaning automatic tests'
	$(foreach dir, $(wildcard */), rm -f $(dir)*.o; rm -f $(dir)*.exe;)