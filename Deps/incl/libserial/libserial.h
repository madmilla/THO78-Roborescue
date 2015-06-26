/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file libserial.h
* @date Created: 26-11-2014
*
* @author ...
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

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
