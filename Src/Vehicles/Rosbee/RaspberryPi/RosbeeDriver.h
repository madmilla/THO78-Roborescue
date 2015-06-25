/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RosbeeDriver.h
* @date Created: 13-05-2015
*
* @author Stefan Dijkman, Nathan Schaaphuizen
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

#ifndef ROSDRIVER_H
#define ROSDRIVER_H

#include "PropCom.h"
#include "EncoderInterface.h"

/**
* @class RosbeeDriver
* @brief This class can manage the basic command for the Rosbee.
*
* The class allows basic operations (driving forward, rotate, stop).
* To do this it makes use of the serial connection.
**/
class RosbeeDriver{
public:
	
	/**
	* @brief Create a new RosbeeDriver object.
	* @param nPropCom PropCom object used for communication with the Propeller.
	**/
	explicit RosbeeDriver(PropCom &nPropCom);

	/**
	* @brief Sends the stop command to stop the Rosbee.
	**/
	void stop();
	
	/**
	* @brief Sends the forward command to make the motors of the Rosbee drive at x speed.
	*
	* The parameters can range from -127 to 127. Where 0 is full stop, and 127 is full speed.
	* Negative values do the same as the positive counterparts with the exception that
	* the motor rotates in the opposite direction.
	* @param motor0Speed Set the speed of motor 0 (left).
	* @param motor1Speed Set the speed of motor 1 (right).
	**/
	void forward(signed char motor0Speed, signed char motor1Speed);
	
	/**
	* @brief Sends the forward command to make the motors of the Rosbee drive at x speed.
	*
	* The parameters can range from -127 to 127. Where 0 is full stop, and 127 is full speed.
	* Negative values do the same as the positive counterparts with the exception that
	* the motor rotates in the opposite direction.
	* @param motorSpeed Set the speed of both motors.
	**/
	void forward(signed char motorSpeed);

	/**
	* @brief Rotate x degrees.
	*
	* The Rosbee will rotate x degrees around its own z-axis. The rotation will be relative
	* to the current facing angel of the Rosbee. Negative values will make the Rosbee rotate
	* in the opposite direction.
	* @param angle The amount to rotate in degrees.
	**/
	void rotate(int angle);

	/**
	 * @brief Drive in a strait line.
	 *
	 * The Rosbee will drive x millimeter forward in a strait line. While doing so if will
	 * check if there are object in front of it. If the path is blocked the Rosbee will automatically
	 * stop.
	 * @param distance Distance to drive in millimeter.
	 * @return Returns true if distance is successfully driven. Returns false if the ride was interrupted.
	 */
	bool drive(int distance);

	/**
	 * @brief Drive to waypoint.
	 *
	 * The Rosbee will drive to the given waypoint. It will do this by first rotating to face
	 * the given offset. After this it will drive towards it in a strait line.
	 * The waypoint given is relative to the Rosbee at the moment of this function call.
	 * This fucntion makes use of the drive() function and thus can be interrupted by obstacles.
	 * @param x Offset on the x-axis.
	 * @param y Offset on the y-axis.
	 * @return Returns true waypoint is successfully reached. Returns false if the ride was interrupted.
	 */
	bool driveToWaypoint(double x, double y);

private:
	PropCom* propCom;
	EncoderInterface encoderLeft;
	EncoderInterface encoderRight;


	//Drive speed of the Rosbee.
	int speed;
	//Diameter of the Rosbee wheel in meters.
	constexpr static const double  wheelDiameter = 0.123;
	//Number of holes in the encoder disk.
	constexpr static const int numberOfHoles = 50;
	//Rotating adjustment.
	constexpr static const double rotateAngleAdjustment = 23.19; //0; // 15.4; //23.19;
	//Multiplier to go from pulses to meters.
	constexpr static const double pulseToMeter = 0.00773;
	//Multiplier to go from pulses to centimeters.
	constexpr static const double pulseToCentiMeter = 0.773;
	//Multiplier to go from pulses to millimeters
	constexpr static const double pulseToMilliMeter = 7.73;
};

#endif // ROSDRIVER_H
