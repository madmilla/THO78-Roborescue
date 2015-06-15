/**
* @Author Marten Wensink
*/

#include "serial.h"
#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>


int fd = -1;

Serial::Serial (std::string & portName) {
	const char* portNameC = reinterpret_cast<const char*>(portName.c_str());
    fd = open (portNameC, O_RDWR | O_NOCTTY | O_NDELAY);  // Open port
    
    if (fd == -1) return ;                             // If the device is not open, return -1
    if (fcntl (fd, F_SETFL, FNDELAY) == 11)              // Open the device in nonblocking mode
       return ;
    struct termios options;                              // Structure with the device's options
    bzero (&options, sizeof (options));                  // Clear all the options
    if (cfsetispeed (&options, B57600) == -1 ||           // Set the baud rate at selected bauds
        cfsetospeed (&options, B57600) == -1)
       return ;
    options.c_cflag |= ( CLOCAL | CREAD |  CS8);         // Configure the device to 8N1: 8 bits, no parity, 1 stop bit
    options.c_cflag &= ~(PARENB | PARODD);
    options.c_cflag &= ~(CSTOPB) ;
    options.c_iflag |= ( IGNPAR | IGNBRK );              // No control
    options.c_cflag &= ~(CRTSCTS) ;
    options.c_cc[VTIME] = 0;                             // Timer unused
    options.c_cc[VMIN] = 2;                              // Return if two characters available for reading
    if (tcsetattr (fd, TCSANOW, &options) == -1)         // Activate the settings
       return;
}

Serial::~Serial () {
    ::close (fd);
}

int Serial::readData(char *buffer, unsigned int nbChar){
	if (getBufferSize() < 1){
		return 0;
	}
	if (getBufferSize() < nbChar){
		nbChar = getBufferSize();
	}
	return read(fd, buffer, nbChar);
}

bool Serial::writeData(char *buffer, unsigned int nbChar){
	return (write(fd,buffer,nbChar) == nbChar);
}

bool Serial::isConnected(){
	return (fd != -1);
}

int Serial::getBufferSize(){
	int nBytes =0;
	ioctl(fd,FIONREAD,&nBytes);
	return nBytes;
}
