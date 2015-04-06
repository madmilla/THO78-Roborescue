#include "SerialPort.h"
#include "Serial.h"
#include "SerialUDPSocket.h"
#ifdef _WIN32
	#include "SerialPortWindows.h"
#endif
#ifdef linux
	#include "SerialPortLinux.h"
#endif

SerialPort::SerialPort(int port, std::string& address)
{
	serialDevice = new SerialUDPSocket(port, address);
}

SerialPort::SerialPort(const char* device)
{
#ifdef _WIN32
	serialDevice = new SerialPortWindows(device);
#endif
#ifdef linux
	serialDevice = new SerialPortLinux(device);
#endif
}

SerialPort::~SerialPort()
{
	delete serialDevice;
}

bool SerialPort::writeData(char* data, int nrOfBytes)
{
	return serialDevice->writeData(data, nrOfBytes);
}

int SerialPort::readData(char* buffer, int nrOfBytes)
{
	return serialDevice->readData(buffer, nrOfBytes);
}