#ifndef _SERIALPORTXP_H
#define _SERIALPORTXP_H
#include "serial.h"
#ifdef _WIN32
#include <windows.h>
#endif

class SerialPortXP : public Serial
{
public:
	explicit SerialPortXP(const char* portName);
	~SerialPortXP();
	int readData(char *buffer, int nbChar) override;
	bool writeData(unsigned char *buffer, int nbChar) override;
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