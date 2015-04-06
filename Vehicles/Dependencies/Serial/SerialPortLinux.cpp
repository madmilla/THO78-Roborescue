#include "SerialPortLinux.h"

SerialPortLinux::SerialPortLinux(const char* deviceName) 
{ 
	open(deviceName, 57600);
}

SerialPortLinux::~SerialPortLinux() 
{
	close();
}

int SerialPortLinux::open(const char * device, unsigned int bauds)
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

void SerialPortLinux::close()
{
	::close (filedescriptor);
}

int SerialPortLinux::writeData(unsigned char* buffer, int nrOfBytes)
{
	if (::write(filedescriptor, buffer, nrOfBytes) != (ssize_t) nrOfBytes)
	{
		return -1;
	}
	return 1;
}

int SerialPortLinux::readData(char* buffer, int nrOfBytes)
{
	unsigned int nbBytesRead = 0;
	while (nbBytesRead < nrOfBytes) 
	{
		auto ptr = static_cast<unsigned char *>(buffer) + nbBytesRead;
		auto ret = ::read(filedescriptor,static_cast<void *>(ptr), nrOfBytes - nbBytesRead);
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