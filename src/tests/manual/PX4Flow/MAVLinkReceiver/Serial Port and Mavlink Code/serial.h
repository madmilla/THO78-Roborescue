#ifndef SERIALCLASS_H_INCLUDED
#define SERIALCLASS_H_INCLUDED

#include <stdio.h>
#include <string>
#include "ioDevice.h"

#if defined(_WIN64) || defined(_WIN32)
	#include <windows.h>
#endif

class Serial: public IoDevice
{
private:
	#if defined(_WIN64) || defined(_WIN32)
		HANDLE hSerial;
		bool connected;
		COMSTAT status;
		DWORD errors;
	#endif
public:
	int readData(char *buffer, unsigned int nbChar) override;
	bool writeData(char *buffer, unsigned int nbChar) override;

	/**
	* Creates a telemetry connection using the given com port.
	* @param portName the name of the port to use.
	*/
	Serial(std::string & portName);
	
	/**
	* Closes the telemetry connection.
	*/
	~Serial();
	
	/**
	* Check if the connection is established properly
	* @return true if connected, false otherwise.
	*/
	bool isConnected() override;

	int getBufferSize() override;

};

#endif // SERIALCLASS_H_INCLUDED
