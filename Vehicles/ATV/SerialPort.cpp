#include "SerialPort.h"
#include "Serial.h"
#include "SerialUDPSocket.h"
#include "SerialPortXP.h"

SerialPort::SerialPort(int port, std::string& address)
{
	serialDevice = new SerialUDPSocket(port, address);
}

SerialPort::SerialPort(const char* device)
{
	serialDevice = new SerialPortXP(device);
}

SerialPort::~SerialPort()
{
	delete serialDevice;
}

int SerialPort::writeData(unsigned char* data, int nrOfBytes)
{
	return serialDevice->writeData(data, nrOfBytes);
}

int SerialPort::readData(char* buffer, int nrOfBytes)
{
	return serialDevice->readData(buffer, nrOfBytes);
}