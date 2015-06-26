SRC += Src/Communication/SerialPort/SerialPort.cpp
ifeq ($(OS),Windows_NT)
	SRC += Src/Communication/SerialPort/SerialPortWindows.cpp
else
	SRC += Src/Communication/SerialPort/SerialPortLinux.cpp
endif
