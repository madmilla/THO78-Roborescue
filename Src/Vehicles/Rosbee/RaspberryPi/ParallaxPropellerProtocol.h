/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file ParallaxPropellerProtocol.h
* @date Created: 7-5-2015
* @version 1.1
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

#ifndef _PARALLAXPROPELLERPROTOCOL_H
#define _PARALLAXPROPELLERPROTOCOL_H

/// @brief Static class holding command bytes.
///
/// The Parallax Propeller Protocol (PPP) class is a static class holding the command bytes
/// that can be send to the propeller. It does not provide any functionality.
class PPP{
public:
	//Motors
	///Set speed for motor 0
	static const unsigned char SET_SPEED_M0 = 0x00;
	///Set speed for motor 1
	static const unsigned char SET_SPEED_M1 = 0x01;
	///Set the brake speed for motor 0
	static const unsigned char SET_BRAKE_SPEED_M0 = 0x02;
	///Set the brake speed for motor 1
	static const unsigned char SET_BRAKE_SPEED_M1 = 0x03;
	///Get firmware version
	static const unsigned char GET_FIRMWARE_VERSION = 0x04;
	///Get error
	static const unsigned char GET_ERROR = 0x05;
   
	//Encoders
	///Get the amount of pulses counted on motor 0
	static const unsigned char GET_PULSE_COUNT_M0 = 0x10;
	///Get the amount of pulses counted on motor 1
	static const unsigned char GET_PULSE_COUNT_M1 = 0x11;
	///Get the amount of pulses counted in the last second on motor 0
	static const unsigned char GET_PULSE_SPEED_M0 = 0x12;
	///Get the amount of pulses counted in the last second on motor 0
	static const unsigned char GET_PULSE_SPEED_M1 = 0x13;
	
	//Ultrasonic Sensors
	///Get the distance from ultrasonic sensor 0
	static const unsigned char GET_DISTANCE_S0 = 0x20;
	///Get the distance from ultrasonic sensor 1
	static const unsigned char GET_DISTANCE_S1 = 0x21;
	///Get the distance from ultrasonic sensor 2
	static const unsigned char GET_DISTANCE_S2 = 0x22;
	///Get the distance from ultrasonic sensor 3
	static const unsigned char GET_DISTANCE_S3 = 0x23;
	///Get the distance from ultrasonic sensor 4
	static const unsigned char GET_DISTANCE_S4 = 0x24;
	///Get the distance from ultrasonic sensor 5
	static const unsigned char GET_DISTANCE_S5 = 0x25;
};

#endif // _PARALLAXPROPELLERPROTOCOL_H
