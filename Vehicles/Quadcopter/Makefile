SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all : Main

Main: $(OBJS)
	g++ $(OBJS) -I ../Dependencies/MAVLink/ardupilotmega -o Main -lws2_32

%.o : %.cpp
	g++ -c -O3 -Wall -Werror -std=gnu++11 $*.cpp -o $*.o