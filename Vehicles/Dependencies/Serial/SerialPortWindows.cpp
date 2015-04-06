#include "SerialPortWindows.h"
#include <iostream>
#define RESTART_WAIT_TIME 2000

SerialPortWindows::SerialPortWindows(const char* deviceName):
	connected{ false },
	errors{ 0 }
{
	serialHandle = CreateFile(deviceName, GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (serialHandle == INVALID_HANDLE_VALUE)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			std::cout << "ERROR: Handle was not attached. Reason: " << deviceName << " not available.\n";
		}
		else
		{
			std::cout << "ERROR!!!";
		}
	}
	else
	{
		DCB dcbSerialParams{ 0 };
		if (!GetCommState(serialHandle, &dcbSerialParams))
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
			if (!SetCommState(serialHandle, &dcbSerialParams))
			{
				std::cout << "ALERT: Could not set Serial Port parameters";
			}
			else
			{
				connected = true;
				PurgeComm(serialHandle, PURGE_RXCLEAR | PURGE_TXCLEAR);
				Sleep(RESTART_WAIT_TIME);
			}
		}
	}
}

SerialPortWindows::~SerialPortWindows()
{
	CloseHandle(serialHandle);
}

int SerialPortWindows::readData(char* buffer, int nrOfBytes)
{
	DWORD bytesRead;
	unsigned int toRead;
	ClearCommError(serialHandle, &errors, &status);
	if (status.cbInQue>0)
	{
		if (status.cbInQue>nrOfBytes)
		{
			toRead = nrOfBytes;
		}
		else
		{
			toRead = status.cbInQue;
		}
		if (ReadFile(serialHandle, buffer, toRead, &bytesRead, nullptr) && bytesRead != 0)
		{
			return bytesRead;
		}
	}
	return -1;
}

bool SerialPortWindows::writeData(unsigned char* data, int nrOfBytes)
{
	DWORD bytesSend;
	if (!WriteFile(serialHandle, data, nrOfBytes, &bytesSend, nullptr))
	{
		ClearCommError(serialHandle, &errors, &status);
		return -1;
	}
	return sizeof(data)/sizeof(char);
}