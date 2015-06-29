/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file propcom.h
* @date Created: 12-4-2015
*
* @author Edwin Koek
* @version 1.0
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

#ifndef PROPCOM_H
#define PROPCOM_H

#include <string>
#include <vector>
#include "LibSerial.h"
#include <mutex>
/**
*@brief Propcom class
*
* This class is responsible for the communication between
* the propeller and the raspberry pi. The functions in this class
* allow for easy usage of the sensors and actuators of the propeller.
*/
class PropCom {
public:
	/**
	*@brief PropCom constructor
	*/
    PropCom();
	/**
	*@brief opens the serial port connection with the propeller.
	*@param port This is the serial port.
	*/
    void open(const std::string &port);
	/**
	*@brief Sends data to the serial port
	*@param command This is the command that the propeller recieves
	*@param value This is the value that the propeller processes based on the given command.
	*/
    void sendData(unsigned char command, unsigned char value);
	/**
	*@brief Reads data from the serial port.
	*@param command The propeller wil return values based on what command it recieves.
	*@param returnedBytes is the amount of bytes that are expected.
	*/
    std::vector<unsigned char> readData(unsigned char command, int returnedBytes);
	/**
	*@brief Sets the speed at which the Rosbee brakes
	*@param speed This is the new brake speed.
	*@param motorNr This defines which motors settings are to be changed. 
	* 1 for the right motor and 0 for the left motor.
	*/
    void setBrakeSpeed(signed char speed, int motorNr);
	/**
	*@brief Sets the speed of the motors
	*@param speed This is the new speed.
	*@param motorNr This defines which motors settings are to be changed. 
	* 1 for the right motor and 0 for the left motor.
	*/
    void setMotorSpeed(signed char speed, int motorNr);
	/**
	*@brief returns the firmware version
	*@return The firmware version.
	*/
    int getFirmwareVersion();
	/**
	*@brief Returns error's.
	*@return Returns error's if they are availible.
	*/
    int getError();
	/**
	*@brief Returns the pulse count of an encoder
	*@param motorNr This defines which motors settings are to be changed. 
	* 1 for the right motor and 0 for the left motor.
	*@return Returns the encoder pulses count
	*/
    int getPulseCount(int motorNr);
	/**
	*@brief Returns the pulse speed of an encoder
	*@param motorNr This defines which motors settings are to be changed. 
	* 1 for the right motor and 0 for the left motor.
	*@return Returns the speed of the encoder pulses
	*/
    int getPulseSpeed(int motorNr);
	/**
	*@brief Returns a distance reading from a ultrasonic sensor.
	*@param ultraSonicSensorNr This defines which ultrasonic sensor will perform the reading.
	*@return The distance that is measured in centimeters.
	*/
    int getDistance(int ultraSonicSensorNr);

private:
    LibSerial com;
    std::mutex mutex;
};


#endif
