COMPILER	:= g++
CPPVERSION	:= -std=gnu++11
CFLAGS		:=

SOURCES = PracticalSocket.cpp SerialUDPSocket.cpp SerialPort.cpp

ifeq ($(TARGET),windows)
	SOURCES += SerialPortWindows.cpp
else
ifeq ($(TARGET),linux)
	SOURCES += SerialPortLinux.cpp
endif
endif

OBJECTS = $(SOURCES:.cpp=.o)

LibSerial.a : $(OBJECTS)
	ar rcs $@ $^

%.o : %.cpp
	g++ -c -std=gnu++11 $^ -o $@