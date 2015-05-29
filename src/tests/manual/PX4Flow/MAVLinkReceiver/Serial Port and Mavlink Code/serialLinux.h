#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
// Configuration and initialization

/*!  \brief Open the serial port
     \param device : Port name /dev/ttyS0, /dev/ttyAMA0, /dev/ttyUSB0 ...

      \n The device is configured 8N1: 8 bits, no parity, 1 stop bit
     \return 1 success
     \return -1 error while opening the device
     \return -2 unable to set non-blocking mode
     \return -3 speed (bauds) not recognized
     \return -4 unable to set baud rate
     \return -5 unable to set flags
*/
int  open (const char * device, unsigned int bauds);

//Close the Serial Connection
void close (void);

//Write a string
int writeString (std::string * string);

int readChar(std::string * pChar);
