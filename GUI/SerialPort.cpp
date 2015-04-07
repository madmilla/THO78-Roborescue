#include "SerialPort.h"
#include "Serial.h"
#ifdef _WIN32
	#include "SerialPortWindows.h"
#endif

SerialPort::SerialPort(int port, std::string& address)
{
}

SerialPort::SerialPort(const char* device)
{
#ifdef _WIN32
	serialDevice = new SerialPortWindows(device);
#endif
}

SerialPort::~SerialPort()
{
	delete serialDevice;
}

bool SerialPort::writeData(unsigned char* data, int nrOfBytes)
{
	return serialDevice->writeData(data, nrOfBytes);
}

int SerialPort::readData(unsigned char* buffer, int nrOfBytes)
{
	return serialDevice->readData(buffer, nrOfBytes);
}