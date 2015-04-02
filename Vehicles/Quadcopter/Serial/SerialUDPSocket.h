#ifndef _SERIALUDPSOCKET_H
#define _SERIALUDPSOCKET_H
#include "Serial.h"
#include "PracticalSocket.h"
#include <string>

class SerialUDPSocket : public Serial
{
public:
	SerialUDPSocket(unsigned short port, string& address);
	int writeData(char* data, int nrOfBytes) override;
	int readData(char* buffer, int nrOfBytes) override;
private:
	UDPSocket socket;
};
#endif