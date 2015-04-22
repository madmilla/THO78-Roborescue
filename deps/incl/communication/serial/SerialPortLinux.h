#ifndef _SERIALPORTLINUX_H
#define _SERIALPORTLINUX_H
#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../Serial.h"

class SerialPortLinux : public Serial
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
	SerialPortLinux(const char* deviceName);
	~SerialPortLinux();
	bool writeData(unsigned char* buffer, int nbBytes) override;
	int readData(unsigned char* buffer, int maxBytes) override;

private:
	int filedescriptor;
	int open(const char * device, unsigned int bauds);
	void close();
};
#endif // _LIB_SERIAL_H