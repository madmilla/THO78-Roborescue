include Makefile.inc

.PHONY: all

all: main.exe

main.exe : main.o quadcopter.o
	$(CXX) $(CXXFLAGS) -o $@ $^