#ifndef _SerialPortLinux_H
#define _SerialPortLinux_H
#include "serial.h"

class SerialPortLinux : public Serial
{
public:
	explicit SerialPortLinux(const char* portName);
	~SerialPortLinux();
	int readData(char *buffer, int nbChar) override;
	bool writeData(unsigned char *buffer, int nbChar) override;
private:
	int filedescriptor;
	int open(const char * device, unsigned int bauds);
	void close();
};
#endif