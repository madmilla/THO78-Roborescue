/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Uart.h
* @date Created: 13-5-2015
* @version 1.0
*
* @author Nathan Schaaphuizen
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

#ifndef _UART_H
#define _UART_H

#include <simpletools.h>
#include "Channel.h"

/// @brief Class for communication between propeller and pc (or PI).
///
/// The Uart class is a half buffer full duplex communication class.
/// It makes use of the UART protocol to send data over the debug port to a
/// attached computer. The UART specifications are (8-n-1) at a baud of 115200 bps. 
/// All incoming data is buffered up to 128 bytes. All data after that is lost.
/// All outgoing data is not buffered but send directly.
/// Note that all data is written and read in a binary format.
/// Note this class makes use of a cog.
class Uart{
private:
  // Read buffer size of 128 chars.
  Channel<char,128> readChannel;
  // This is the minimum stack size required to for the cog (thread) to run.
  // Don't set it below 192.
  char stack[192]; 
  int cogId;

  static void readBuffer(void*);
  
public:
  /// @brief Creates a Uart object.
  ///
  /// Initializes a free cog for use. 
  Uart();
  
  /// @brief Destroys  the Uart object.
  ///
  /// Frees the used cog.
  ~Uart();
  
  /// @brief Read a character.
  ///
  /// Read one character from the buffer.
  /// @return Next character in buffer.
  char readChar();
  
  /// @brief Read a integer.
  ///
  /// Read the next four characters from the buffer and 
  /// converts these to a integer.
  /// @return Next integer in buffer.
  int readInt();
  
  /// @brief Send a character.
  ///
  /// Directly sends a character.
  /// @param data The character to be sent.
  void send(char data);
  
  /// @brief Send a integer.
  ///
  /// Converts an integer to four characters and directly sends these.
  /// @param data The integer to be sent.
  void send(int data);
    
};  

#endif // _UART_H