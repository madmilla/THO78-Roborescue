/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file IMU.h
* @date Created: 26-6-2015
*
* @author Edwin Koek
* @version 1.0
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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

#ifndef IMU_H
#define IMU_H
/**
*@brief IMU class
*/
class IMU{
public:
	/**
	*@brief IMU constructor
	*/
    IMU();
	/**
	*@brief Sets the IMU values according to the lastest reading.
	*@param newxgyro The new x axis angle of the gyroscope.
	*@param newygyro The new y axis angle of the gyroscope.
	*@param newzgyro The new z axis angle of the gyroscope.
	*@param newxacc The new x axis reading of the accelerometer.
	*@param newyacc The new y axis reading of the accelerometer.
	*@param newzacc The new z axis reading of the accelerometer.
	*@param dTime The time between last reading and current reading.
	*/
    void newReading(float newxgyro ,
                    float newygyro,
                    float newzgyro,
                    float newxacc,
                    float newyacc ,
                    float newzacc,
                    double dTime);
	/**
	*@brief Calculates roll and pitch
	*
	* This function calculates the roll and pitch by combining gyroscope and accelerometer readings.
	*@param dTime The since last sensor measurement.
	*/
    void complementaryFilter(double dTime);
	/**
	*@brief returns the roll angle of the Rosbee
	*@return The roll angle of the Rosbee.
	*/
    float getRoll();
	/**
	*@brief returns the pitch angle of the Rosbee
	*@return the pitch angle of the Rosbee.
	*/
    float getPitch();
	/**
	*@brief returns the yaw angle of Rosbee
	*@return The yaw angle of the Rosbee
	*/
    float getYaw();


private:
    float xgyro ,ygyro,zgyro;
    float xacc, yacc ,zacc;
    float roll, pitch, yaw;
};


#endif // IMU_H
