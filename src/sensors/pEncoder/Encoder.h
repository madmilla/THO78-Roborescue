/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Encoder.h
* @date Created: 1-5-2015
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

#ifndef _ENCODER_H
#define _ENCODER_H

/// @brief Simple interface for the light encoder.
///
/// The Encoder class provides a simple interface for interfacing between
/// the Parallax Propeller and the light encoder(s).
/// This class continuous polls the light encoder and counts high to low phase transition.
/// To do this uninterrupted this class makes use of on of the Propeller cogs allocated with 192 bytes of memory.
class Encoder{
private:
  int pin;
  unsigned int pulseCount;
  int speed;
  // This is the minimum stack size required to for the cog (thread) to run.
  // Don't set it below 192.
  char stack[192];  
  int cogId;
  
  static void run(void* obj);
  
public:
  
  /// @brief Create a new Encoder object.
  ///
  /// The contractor will start the pulse counting on a new cog. Make sure one or more cogs are available.
  /// @param newPin The pin on which the encoder is connected.
  explicit Encoder(int newPin);
  
  /// @brief Destroys this object freeing the cog.
  ~Encoder();
  
  /// @brief Get pulse count.
  ///
  /// Get the amount of pulses counted since the creation of this object.
  /// @return The pulse count.
  unsigned int getPulseCount();
  
  /// @brief Get pulse speed.
  ///
  /// Get the amount of pulses counted each second.
  /// Since we use a rotary encoder disk this effectively translates in the rotation speed.
  /// The speed is calculated from a second ago and may lag behind the reality a little.
  /// @return The pulse count last second.
  int getSpeed();
};
  
#endif // _ENCODER_H