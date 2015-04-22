COMPILER	:= g++
CPPVERSION	:= -std=gnu++11
CFLAGS		:=

SOURCES = udp/PracticalSocket.cpp udp/SerialUDPSocket.cpp SerialPort.cpp

ifeq ($(TARGET),windows)
	SOURCES += serial/SerialPortWindows.cpp
else
ifeq ($(TARGET),linux)
	SOURCES += serial/SerialPortLinux.cpp
endif
endif

OBJECTS = $(SOURCES:.cpp=.o)

LibSerial.a : $(OBJECTS)
	ar rcs $@ $^

%.o : %.cpp
	g++ -c -std=gnu++11 $^ -o $@