#include "SerialPortXP.h"
#ifdef linux
SerialPortXP::SerialPortXP(const char* deviceName) 
{ 
	open(deviceName, 57600);
}

SerialPortXP::~SerialPortXP() 
{
	close();
}

int SerialPortXP::open(const char * device, unsigned int bauds)
{
	filedescriptor = ::open(device, O_RDWR | O_NOCTTY | O_NDELAY);
	if (filedescriptor == -1) 
	{
		return -1;
	}
	if (fcntl (filedescriptor, F_SETFL, FNDELAY) == 11)
	{
		return -2;
	}
	struct termios options;
	bzero (&options, sizeof (options));
	speed_t speed;
	switch(bauds) 
	{
		case 110 :     
			speed = B110; break;
		case 300 :     
			speed = B300; break;
		case 600 :     
			speed = B600; break;
		case 1200 :     
			speed = B1200; break;
		case 2400 :     
			speed = B2400; break;
		case 4800 :     
			speed = B4800; break;
		case 9600 :     
			speed = B9600; break;
		case 19200 :    
			speed = B19200; break;
		case 38400 :    
			speed = B38400; break;
		case 57600 :    
			speed = B57600; break;
		case 115200 :   
			speed = B115200; break;
		default :       
			return -3;
	}
	if (cfsetispeed (&options, speed) == -1 || cfsetospeed (&options, speed) == -1)
	{
		return -4;
	}
	
	options.c_cflag |= ( CLOCAL | CREAD |  CS8);
	options.c_cflag &= ~(PARENB | PARODD);
	options.c_cflag &= ~(CSTOPB);
	options.c_iflag |= ( IGNPAR | IGNBRK );
	options.c_cflag &= ~(CRTSCTS);
	options.c_cc[VTIME] = 0;
	options.c_cc[VMIN] = 2;
	if (tcsetattr (filedescriptor, TCSANOW, &options) == -1)
	{
		return -5;
	}
	return 1;
}

void SerialPortXP::close()
{
	::close (filedescriptor);
}

int SerialPortXP::writeData(unsigned char* data, int nrOfBytes)
{
	if (::write(filedescriptor, buffer, nbBytes) != (ssize_t) nbBytes)
	{
		return -1;
	}
	return 1;
}

int SerialPortXP::readData(char* buffer, int nrOfBytes)
{
	unsigned int nbBytesRead = 0;
	while (nbBytesRead < maxBytes) 
	{
		auto ptr = static_cast<unsigned char *>(buffer) + nbBytesRead;
		auto ret = ::read(filedescriptor,static_cast<void *>(ptr), maxBytes - nbBytesRead);
		if (ret == -1) 
		{
			return -1;
		}
		if (ret > 0)
		{   
			nbBytesRead += ret;
		}
	}
	return 1;
}
#endif
#ifdef _WIN32
#include <iostream>
#define RESTART_WAIT_TIME 2000

SerialPortXP::SerialPortXP(const char* deviceName):
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

SerialPortXP::~SerialPortXP()
{
	CloseHandle(serialHandle);
}

int SerialPortXP::readData(char* buffer, int nrOfBytes)
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

bool SerialPortXP::writeData(unsigned char* data, int nrOfBytes)
{
	DWORD bytesSend;
	if (!WriteFile(serialHandle, data, nrOfBytes, &bytesSend, nullptr))
	{
		ClearCommError(serialHandle, &errors, &status);
		return -1;
	}
	return sizeof(data)/sizeof(char);
}
#endif