#ifndef _SERIALPORTXP_H
#define _SERIALPORTXP_H
#include "serial.h"
#include <windows.h>

class SerialPortXP : public SerialPort
{
public:
	explicit SerialPortXP(const char* portName);
	~SerialPortXP();

	int readData(char *buffer, unsigned int nbChar) override;
	bool writeData(unsigned char *buffer, unsigned int nbChar) override;
	int getBufferSize() override;
	bool isConnected() override;
private:
#ifdef _WIN32
	HANDLE serialHandle;
	bool connected;
	COMSTAT status;
	DWORD errors;
#endif
#ifdef linux
	int filedescriptor;
	int open(const char * device, unsigned int bauds);
	void close();
#endif
};
#endif