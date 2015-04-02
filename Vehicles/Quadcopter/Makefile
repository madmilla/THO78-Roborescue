SRC = $(wildcard *.cpp)
SRC += $(Serial/*.cpp)
OBJS = $(SRC:.cpp=.o)

all : Main

Main: $(OBJS)
	g++ $(OBJS) -I ../Dependencies/MAVLink/ardupilotmega -o Main -lws2_32

%.o : %.cpp
	g++ -c -std=gnu++11 $*.cpp -o $*.o

leftRight: $(OBJS)
	g++ -std=gnu++11 testLeftRight.cpp -o testLeftRight.exe
	./testLeftRight.exe