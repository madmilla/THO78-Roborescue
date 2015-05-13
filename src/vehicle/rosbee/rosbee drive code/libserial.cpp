/*!
 \file    libserial.cpp
 \brief   Class to manage the serial port on Linux systems
 \version 1.0
 \date    26 november 2014
*/

#include "libserial.h"

/*! \brief Constructor of class LibSerial
 */
LibSerial::LibSerial (void) { }

/*! \brief Destructor of class LibSerial. It closes the connection
 */
LibSerial::~LibSerial (void) {
   close();
}

// Configuration and initialization

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
int LibSerial::open (const char * device, unsigned int bauds) {

    // Open device
    fd = ::open (device, O_RDWR | O_NOCTTY | O_NDELAY);  // Open port
    if (fd == -1) return -1;                             // If the device is not open, return -1
    if (fcntl (fd, F_SETFL, FNDELAY) == 11)              // Open the device in nonblocking mode
       return -2;

    // Set parameters
    struct termios options;                              // Structure with the device's options
    bzero (&options, sizeof (options));                  // Clear all the options
    speed_t speed;
    switch (bauds) {                                     // Set the speed (bauds)
       case 110  :     speed = B110;    break;
       case 300  :     speed = B300;    break;
       case 600  :     speed = B600;    break;
       case 1200 :     speed = B1200;   break;
       case 2400 :     speed = B2400;   break;
       case 4800 :     speed = B4800;   break;
       case 9600 :     speed = B9600;   break;
       case 19200 :    speed = B19200;  break;
       case 38400 :    speed = B38400;  break;
       case 57600 :    speed = B57600;  break;
       case 115200 :   speed = B115200; break;
       default :       return -3;
    }
    if (cfsetispeed (&options, speed) == -1 ||           // Set the baud rate at selected bauds
        cfsetospeed (&options, speed) == -1)
       return -4;

    options.c_cflag |= ( CLOCAL | CREAD |  CS8);         // Configure the device to 8N1: 8 bits, no parity, 1 stop bit
    options.c_cflag &= ~(PARENB | PARODD);
    options.c_cflag &= ~(CSTOPB) ;
    options.c_iflag |= ( IGNPAR | IGNBRK );              // No control
    options.c_cflag &= ~(CRTSCTS) ;
    options.c_cc[VTIME] = 0;                             // Timer unused
    options.c_cc[VMIN] = 2;                              // Return if two characters available for reading
    if (tcsetattr (fd, TCSANOW, &options) == -1)         // Activate the settings
       return -5;
    return 1;                                            // Success
}


/*! \brief Close the connection with the current device
 */
void LibSerial::close (void) {
    ::close (fd);
}


// Read/Write operation on characters

/*!  \brief Wait for a char from the serial device and return the data read
     \param pChar : char read on the serial device
     \return 1 success
     \return -1 error while reading the char
 */
int LibSerial::readChar (char * pChar) {
   if (::read (fd, pChar, 1) != 1)    // Try to read a char from the device
      return -1;                    // Error while reading
   return 1;                        // Read successfull
}

/*!  \brief Write a char on the current serial port
     \param Char : char to send on the port
     \return 1 success
     \return -1 error while writting data
 */
int LibSerial::writeChar (char Char) {
   if (::write (fd, &Char, 1) != 1) // Write the char
        return -1;                  // Error while writting
    return 1;                       // Write operation successfull
}


// Read/Write operation on strings

/*!  \brief Read a string from the serial device
     \param string : string read on the serial device
     \param finalChar : final char of the string
     \param maxChars : maximum allowed number of chars read
     \return >0 success, return the number of chars read
     \return -1 error while reading the char
     \return -2 maxChars is reached
 */
int LibSerial::readString (char * string, char finalChar, unsigned int maxChars) {
   unsigned int  nbChars = 0;                   // Number of chars read
   int           ret;                           // Returned value from read
   while (nbChars < maxChars) {                 // While the buffer is not full
      ret = readChar (&string[nbChars]);        // Read a char with the restant time
      if (ret == 1) {                           // If a char has been read
         if (string[nbChars] == finalChar) {    // Check if it is the final char
            string [++nbChars] = '\0';          // Yes : add the end character '\0'
            return nbChars;                     // Return the number of chars read
         }
         nbChars++;                             // If not, just increase the number of chars read
      }
      if (ret < 0) return ret;                  // Error while reading : return the error number
    }
    return -2;                                  // Buffer is full : return -3
}

/*!  \brief Write a string on the current serial port
     \param string : string to send on the port (must be terminated by '\0')
     \return 1 success
     \return -1 error while writting data
 */
int LibSerial::writeString (const char * string) {
   int lenght = strlen (string);                // Lenght of the string
   if (::write(fd, string, lenght) != lenght)   // Write the string
     return -1;                                 // Error while writing
   return 1;                                    // Write operation successfull
}

// Read/Write operation on bytes

/*!  \brief Write an array of data on the current serial port
     \param buffer : array of bytes to send on the port
     \param nbBytes : number of bytes to send
     \return 1 success
     \return -1 error while writting data
 */
int LibSerial::write (const void * buffer, unsigned int nbBytes) {
   if (::write (fd, buffer, nbBytes) != (ssize_t) nbBytes)  // Write data
      return -1;                                            // Error while writing
   return 1;                                                // Write operation successfull
}

/*!  \brief Read an array of bytes from the serial device
     \param buffer : array of bytes read from the serial device
     \param maxBytes : maximum allowed number of bytes to read
     \return 1 success, return the number of bytes read
     \return -1 error while reading the bytes
 */
int LibSerial::read (void * buffer, unsigned int maxBytes) {
    unsigned int nbBytesRead = 0;
    while (nbBytesRead < maxBytes) {                                 // While not all bytes read
      unsigned char * ptr =(unsigned char *) buffer + nbBytesRead;   // Compute the position of the current byte
      int ret = ::read (fd,(void *) ptr, maxBytes - nbBytesRead);    // Try to read some bytes on the device
      if (ret == -1) return -1;                                      // Error while reading
      if (ret > 0)                                                   // One or several byte(s) has been read on the device
         nbBytesRead += ret;                                         // Increase the number of read bytes
   }
   return 1;                                                         // Success : bytes has been read
}


// Special operation

/*! \brief Empty send and receive buffers
 */
void LibSerial::flush (void) {
   tcflush (fd, TCIOFLUSH);
}

/*! \brief  Return the number of bytes in the receive buffer
    \return The number of bytes in the receive buffer
 */
int LibSerial::peek (void) {
   int nbBytes = 0;
   ioctl (fd, FIONREAD, &nbBytes);
   return nbBytes;
}
