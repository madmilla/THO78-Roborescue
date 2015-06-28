#ifndef _DATA_PORT_H
#define _DATA_PORT_H
#include <cstdlib>

class DataPort
{
public:
	virtual size_t readData(unsigned char* buffer, int nrOfBytes) = 0;
	virtual size_t writeData(const unsigned char* buffer, int nrOfBytes) = 0;
};
#endif