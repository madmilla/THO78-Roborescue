#ifndef _LIB_SERIAL_H
#define _LIB_SERIAL_H


#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

/*! \class LibSerial
    \brief    This class can manage a serial port.
              The class allows basic operations (opening the connection, reading, writing data and closing the connection).
 */

class LibSerial {
public:
    // Constructor of the class
    LibSerial  (void);

    // Destructor
    ~LibSerial (void);


    // Configuration and initialization

    // Open a device
    int  open (const char * device, unsigned int bauds);

    // Close the current device
    void close (void);


    // Read/Write operation on characters

    // Write a char
    int writeChar (char);

    // Read a char
    int readChar    (char * pByte);


    // Read/Write operation on strings

    // Write a string
    int writeString (const char * string);

    // Read a string
    int readString  (char * string, char finalChar, unsigned int maxBytes);


    // Read/Write operation on bytes

    // Write an array of bytes
    int write (const void * buffer, unsigned int nbBytes);

    // Read an array of bytes
    int read (void * buffer, unsigned int maxBytes);


    // Special operations

    // Empty the send and receive buffer
    void flush (void);

    // Return the number of bytes in the receive buffer
    int peek (void);

private:
    int fd;
};

/*!
  \mainpage LibSerial class

  \brief
    The class LibSerial offers simple access to the serial port devices for Linux.
    It can be used for any serial device (Built-in serial port, USB to RS232 converter,
    Arduino board, Raspberry Pi or any hardware using or emulating a serial port)
    The class allows basic operations like :
    - opening and closing connection
    - reading data (characters, strings or arrays of bytes)
    - writing data (characters, strings or arrays of bytes)
    - peeking data and flushing the receive buffer
*/

#endif // _LIB_SERIAL_H
