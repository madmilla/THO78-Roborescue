/// @file ParallaxPropellerProtocol.h
/// @author Nathan Schaaphuizen
/// @version 1.1

#ifndef _PARALLAXPROPELLERPROTOCOL_H
#define _PARALLAXPROPELLERPROTOCOL_H

/// Class PPP
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
