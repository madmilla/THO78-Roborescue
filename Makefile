include Makefile.inc

.PHONY: all

all: main.exe

main.exe : main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)