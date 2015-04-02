#ifndef SERIAL_H
#define SERIAL_H
class Serial
{
public:
	virtual int writeData(char* data, int nrOfBytes) = 0;
	virtual int readData(char* buffer, int nrOfBytes) = 0;
};
#endif