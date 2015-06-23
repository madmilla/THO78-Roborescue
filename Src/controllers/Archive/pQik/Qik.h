/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Qik.h
* @date Created: 13-4-2015
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

#ifndef _QIK_H
#define _QIK_H

/// @brief Simple interface for the Qik 2s12v10.
///
/// The Qik class provides a simple interface for interfacing between
/// the Parallax Propeller and the Qik 2s12v10 motor controller.
/// This class makes use of the Compact Protocol and can be used to interface
/// with one Qik motor controller at the time. 
class Qik{
private:
  /// Microsecond.
  static const int US = 1000*1000;
  /// Input
  static const int INPUT = 0;
  /// Output
  static const int OUTPUT = 1;

  int tx;
  int rx;

  int bitWidth;
  static const unsigned char cSYN = 0xAA;   //Synchronisation
  static const unsigned char cFWV = 0x81;   //Firmware Version
  static const unsigned char cERR = 0x82;   //Error
  static const unsigned char cM0F = 0x88;   //Motor M0 Forward 
  static const unsigned char cM0R = 0x8A;   //Motor M0 reverse 
  static const unsigned char cM1F = 0x8C;   //Motor M1 Forward 
  static const unsigned char cM1R = 0x8E;   //Motor M1 reverse
  static const unsigned char cM0B = 0x86;   //Motor M0 Brake
  static const unsigned char cM1B = 0x87;   //Motor M1 Brake
  
  void TX(unsigned char byte);
  unsigned char RX();
  
public:
  
  /// @brief Enum class Motor.
  ///
  /// Class holding the available motors.
  enum class Motor{
    M0,
    M1  
  };
      
 
  /// @brief Create a new Qik object.
  ///
  /// @param pinTx The pin used to send bytes and needs to be connected to the RX pin on the Qik 2s12v10. 
  /// @param pinRx The pin used to receive bytes and need to be connected to the TX pin on the Qik 2s12v10.
  /// @param baudRate The baud rate in bits/sec. This can range between 1200 and 115200.
  Qik(int pinTx, int pinRx, int baudRate);
  
  /// @brief Get the firmware version.
  ///
  /// Get the version of the firmware currently installed.
  /// @return The firmware version as a ascii byte. This '1' (int 49) for older and '2' (int 50) voor newer versions.
  int getFirmwareVersion();
  
  /// @brief Get the occured error.
  ///
  /// Get the occured error(s) since the last getError() call.
  /// @return The a byte representing one or more erros. 0 = No error. 
  /// For the complete error list see: https://www.pololu.com/docs/0J29/5.c
  int getError();
  
  /// @brief Set the motor speed.
  ///
  /// Set the motor speed. If the motor speed != 0 the motor will start spinning.
  /// @param motor The motor you wish to adjust. This can be Motor::M0 or Motor::M1.
  /// @param speed The motor speed ranging from -127 to 127 included. A negative value represents the same speed
  /// as its positive only in the opposite direction. 
  void setMotorSpeed(Motor motor, signed char speed);
  
  /// @brief Set the break strength.
  ///
  /// Set the motor brake strength. This determines how hard the motor will break if the speed is set to 0.
  /// @param motor The motor you wish to adjust. This can be Motor::M0 or Motor::M1.
  /// @param strength The motor brake strenght ranging from 0 to 127. A value 0 will apply the weakest (almost nothing)
  /// and a value of 127 the strongest brake power. 
  void setBrakePower(Motor motor, unsigned char strength);
  
};
#endif // _QIK_H