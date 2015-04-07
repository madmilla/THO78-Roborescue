SOURCES := main.cpp
OBJS = $(SOURCES:.cpp=.o)

ifeq ($(TARGET),windows)
	SOURCES += SerialPortWindows.cpp
else
ifeq ($(TARGET),linux)
	SOURCES += SerialPortLinux.cpp
endif
endif

main: $(OBJS)
	g++ $(OBJS) -o main

main.o: %.o
	g++ -c -std=gnu++11 $*.cpp -o $*.o


%.o : %.cpp
 g++ -c -std=gnu++11 $*.cpp -o $*.o

LibSerial.a : $(OBJS)
	ar rcs $@ $^
 
clean:
	rm -f $(OBJS) *.o