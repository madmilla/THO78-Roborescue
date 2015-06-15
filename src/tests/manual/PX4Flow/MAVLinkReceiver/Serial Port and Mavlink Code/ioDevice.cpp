#include "ioDevice.h"

int IoDevice::readData(std::string & str){
	const int dataLength = getBufferSize();
	if (dataLength <= 0){
		return -1;
	}
	char* incomingData = new char[dataLength+1];
	incomingData[dataLength] = '\0';

	int readBytes = readData(incomingData, dataLength);

	str = incomingData;
	delete[] incomingData;

	return readBytes;
}

bool IoDevice::writeData(std::string & str){
	char* strC = const_cast<char*>(str.c_str());
	return writeData(strC, str.length());
}
