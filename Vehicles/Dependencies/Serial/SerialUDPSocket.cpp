#include "SerialUDPSocket.h"

SerialUDPSocket::SerialUDPSocket(unsigned short port, std::string& address)
{
	socket.connect(address, port);
}

bool SerialUDPSocket::writeData(unsigned char* data, int nrOfBytes)
{
	socket.send(data, nrOfBytes);
	return true;
}

int SerialUDPSocket::readData(unsigned char* data, int nrOfBytes)
{
	return socket.recv(data, nrOfBytes);
}