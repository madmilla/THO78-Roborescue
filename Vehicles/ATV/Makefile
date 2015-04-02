SRC = $(wildcard *.cpp)
SRC += $(Serial/*.cpp)
OBJS = $(SRC:.cpp=.o)

all : Main

Main: $(OBJS)
	g++ $(OBJS) -I ../Dependencies/MAVLink/ardupilotmega -o ATV -lws2_32

%.o : %.cpp
	g++ -c -std=gnu++11 $*.cpp -o $*.o