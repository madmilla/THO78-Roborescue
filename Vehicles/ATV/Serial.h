#ifndef SERIAL_H
#define SERIAL_H
class Serial
{
public:
	virtual ~Serial(){}
	virtual bool writeData(unsigned char* data, int nrOfBytes){return true;}
	virtual int readData(char* buffer, int nrOfBytes){return 1;}
};
#endif