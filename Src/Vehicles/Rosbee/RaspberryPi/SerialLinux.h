#ifndef _LIB_SERIAL_H
#define _LIB_SERIAL_H
#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

/// @cond

class SerialLinux 
{
public:
	/*!  \brief Open the serial port
		 \param device : Port name /dev/ttyS0, /dev/ttyAMA0, /dev/ttyUSB0 ...
		 \param bauds :  Baud rate of the serial port.

		  \n Supported baud rate for Linux :\n
				   - 110
				   - 300
				   - 600
				   - 1200
				   - 2400
				   - 4800
				   - 9600
				   - 19200
				   - 38400
				   - 57600
				   - 115200

		  \n The device is configured 8N1: 8 bits, no parity, 1 stop bit

		 \return 1 success
		 \return -1 error while opening the device
		 \return -2 unable to set non-blocking mode
		 \return -3 speed (bauds) not recognized
		 \return -4 unable to set baud rate
		 \return -5 unable to set flags
	*/
	SerialLinux(const char* deviceName, unsigned int baudrate);
	~SerialLinux();
	int writeChar(char);
	int readChar(char * pByte);
	int writeString(const char * string);
	int readString (char * string, char finalChar, unsigned int maxBytes);
	int write(const void * buffer, unsigned int nbBytes);
	int read(void * buffer, unsigned int maxBytes);
	void flush();
	int peek();

private:
	int filedescriptor;
	int open(const char * device, unsigned int bauds);
	void close();
};
#endif // _LIB_SERIAL_H

/// @endcond
