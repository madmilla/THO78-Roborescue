#ifndef _SERIALPORTXP_H
#define _SERIALPORTXP_H
#include "Serial.h"
#include <windows.h>

class SerialPortWindows : public Serial
{
public:
	explicit SerialPortWindows(const char* portName);
	~SerialPortWindows();
	int readData(unsigned char* buffer, int nbChar) override;
	bool writeData(unsigned char *buffer, int nbChar) override;
private:
	HANDLE serialHandle;
	bool connected;
	COMSTAT status;
	DWORD errors;
};
#endif
