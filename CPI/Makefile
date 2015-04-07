SRC = $(wildcard *.cpp)
SRC += $(*.cpp)
OBJS = $(SRC:.cpp=.o)

all : Main

Main: $(OBJS)
	g++ $(OBJS)

%.o : %.cpp
	g++ -c -std=gnu++11 $*.cpp -o $*.o