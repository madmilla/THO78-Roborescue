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
CFLAGS = -Wall -Wextra -pedantic -std=c++11

.PHONY: all clean vb1 vb2

vb1: vb1\Main.o vb1\Class.o
	$(CC) $(CFLAGS) $^ -o $@\$@ $(LDFLAGS)
	
vb2: vb2\Main.o
	$(CC) $(CFLAGS) $^ -o $@\$@ $(LDFLAGS)

all: vb1 vb2
	
#######Generic rules#######
%.o: %.cpp
	$(CC) -c $(CFLAGS) $^ -o $@
	
clean:
	@echo 'Cleaning automatic tests'
	$(foreach dir, $(wildcard */), rm -f $(dir)*.o; rm -f $(dir)*.exe;)