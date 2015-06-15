#ifndef IODEVICE_H_INCLUDED
#define IODEVICE_H_INCLUDED
#include <string>

class IoDevice{
public:
	virtual int readData(char *buffer, unsigned int nbChar) = 0;
	virtual bool writeData(char *buffer, unsigned int nbChar) = 0;

	/**
	* Read data from this connection.
	* @param str reference to the string to write the data to.
	* @return the amount of bytes read.
	*/
	int readData(std::string & str);

	/**
	* Write data to this connection.
	* @param str reference to the string to write.
	* @return true if writing was successfull, false otherwise.
	*/
	bool writeData(std::string & str);
	
	/**
	* Check if the connection is established properly
	* @return true if connected, false otherwise.
	*/
	virtual bool isConnected() = 0;

	virtual int getBufferSize() = 0;

};
#endif
