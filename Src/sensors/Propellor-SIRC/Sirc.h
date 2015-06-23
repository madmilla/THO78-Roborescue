/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Sirc.h
* @date Created: 28-4-2015
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

#ifndef _SIRC_H
#define _SIRC_H

/// @brief Class for receiving and reading the Sony SIRC protocol.
///
/// The Sirc class provides a simple interface for interpreting the Sony SIRC protocol 
/// using the TSOP348 IR receiver.
/// Please note that this class expected the following from the IR reciver: 
/// active low: 1 = no signal, 0 = signal is received. 
/// I'm aware that simpeltools.h provides a similar functionalty. But for some reason it didn't work
/// correctly with either my remote or the TSOP348 IR receiver.
class Sirc{
private:
  /// Timout value.
  static const int TIMEOUT = -1;
  int pin;
  int timeout;
  
  /// Helper function to count pulse width.
  ///
  /// Function to count the width of a pluse.
  /// @return Pulse width multiplied  by 100 us. Aka a return value of 24 is 2400 us in real time.
  int getPulseWidth();
    
public:
  /// @brief Create a new Sirc object.
  ///
  /// @param inputPin The pin connected to the OUT of the IR receiver. 
  explicit Sirc(int inputPin);
  
  /// @brief Get raw remote code.
  /// 
  /// Get the unparsed 12 bits remote code.
  /// The address is stored LSB in the first 5 bits.
  /// The command is stored LSB in the next 7 bits.
  /// This function will block until a valid code is received or until a timeout is triggered (timeout disabled by default).
  /// @return The unparsed remote code received from the remote control. Returns -1 on timeout.
  int getRawCode();
  
  /// @brief Get remote control codes.
  ///
  /// Receive and parse the remote codes.
  /// This function will block until a valid code is received or until a timeout is triggered (timeout disabled by default).
  /// The parsed values will be stored in the given parameter  pointer.
  /// Note: the parameter will be left unchanged on timeout.
  /// @param command Will be filled with the remote command (key code).
  /// @param address Will be filled with device address.
  /// @return Returns true on successful read. Returns false on timeout.
  bool getCode(int *command, int *address);
  
  /// @brief Set timeout.
  ///
  /// Set the amount of time (in milliseconds) to wait for a remote signal.
  /// If no signal is received in this time a timeout is casted.
  /// Note: setting a too short time may result in missing the signal all together.
  /// @param ms Time to wait in milliseconds. Set to 0 to disable timeout.
  void setTimeout(int ms);
  
};

#endif // _SIRC_H  