#include "SerialUDPSocket.h"

SerialUDPSocket::SerialUDPSocket(unsigned short port, std::string& address)
{
	socket.connect(address, port);
}

bool SerialUDPSocket::writeData(char* data, int nrOfBytes)
{
	socket.send(data, nrOfBytes);
	return 1;
}

int SerialUDPSocket::readData(char* data, int nrOfBytes)
{
	return socket.recv(data, nrOfBytes);
}