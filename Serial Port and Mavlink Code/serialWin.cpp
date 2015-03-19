#include "serial.h"
#include "serialWin.h"
#include <iostream>

#define RESTART_WAIT_TIME 2000


Serial::Serial(std::string & portName)
{
	this->connected = false;

	this->errors = 0;

	this->hSerial = CreateFile(portName.c_str(),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (this->hSerial == INVALID_HANDLE_VALUE)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND){
			std::cout << "ERROR: Handle was not attached. Reason: "<<portName<<" not available.\n";

		}
		else
		{
			std::cout << "ERROR!!!";
		}
	}
	else
	{
		DCB dcbSerialParams = { 0 };

		if (!GetCommState(this->hSerial, &dcbSerialParams))
		{
			std::cout << "failed to get current serial parameters!";
		}
		else
		{
			dcbSerialParams.BaudRate = CBR_57600;
			dcbSerialParams.ByteSize = 8;
			dcbSerialParams.StopBits = ONESTOPBIT;
			dcbSerialParams.Parity = NOPARITY;
			
			dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

			if (!SetCommState(hSerial, &dcbSerialParams))
			{
				std::cout << "ALERT: Could not set Serial Port parameters";
			}
			else
			{
				this->connected = true;
				PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
				Sleep(RESTART_WAIT_TIME);
			}
		}
	}

}

Serial::~Serial()
{
	if (this->connected)
	{
		this->connected = false;
		CloseHandle(this->hSerial);
	}
}

int Serial::readData(char *buffer, unsigned int nbChar)
{
	DWORD bytesRead;
	unsigned int toRead;

	ClearCommError(this->hSerial, &this->errors, &this->status);

	if (this->status.cbInQue>0)
	{
		if (this->status.cbInQue>nbChar)
		{
			toRead = nbChar;
		}
		else
		{
			toRead = this->status.cbInQue;
		}

		if (ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL) && bytesRead != 0)
		{
			return bytesRead;
		}

	}

	return -1;

}

bool Serial::writeData(char *buffer, unsigned int nbChar)
{
	DWORD bytesSend;

	if (!WriteFile(this->hSerial, (void *)buffer, nbChar, &bytesSend, 0))
	{
		ClearCommError(this->hSerial, &this->errors, &this->status);

		return false;
	}
	else
		return true;
}

int Serial::getBufferSize(){
	ClearCommError(this->hSerial, &this->errors, &this->status);
	return this->status.cbInQue;
}

bool Serial::isConnected()
{
	return this->connected;
}
