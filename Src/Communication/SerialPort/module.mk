SRC += src/communication/SerialPort/SerialPort.cpp
ifeq ($(OS),Windows_NT)
	SRC += src/communication/SerialPort/SerialPortWindows.cpp
else
	SRC += src/communication/SerialPort/SerialPortLinux.cpp
endif