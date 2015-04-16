#include "SerialPort.h"
#include "Serial.h"
#include "udp/SerialUDPSocket.h"
#ifdef _WIN32
	#include "serial/SerialPortWindows.h"
#endif
#ifdef linux
	#include "serial/SerialPortLinux.h"
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

bool SerialPort::writeData(unsigned char* data, int nrOfBytes)
{
	return serialDevice->writeData(data, nrOfBytes);
}

int SerialPort::readData(unsigned char* buffer, int nrOfBytes)
{
	return serialDevice->readData(buffer, nrOfBytes);
}