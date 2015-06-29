/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file DataRetriever.cpp
* @date Created: 22-6-2015
*
* @author Kjeld Perquin
* @author Edwin Koek - Added Compass and IMU
* @version 2.0
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

#include "DataRetriever.h"
#include <iostream>


DataRetriever::DataRetriever(const char* deviceName, unsigned int baudrate, Compass& compass, IMU& imu):
    serialPort{deviceName, baudrate},
    compass{compass},
    imu{imu},
    newCompass{ false },
    newAttitude{ false },
    newIMU{ false }
{
}

__mavlink_scaled_imu2_t DataRetriever::getIMUValues()
{
    newIMU = false;
    return IMU2Values;
}

__mavlink_attitude_t DataRetriever::getAttitudeValues()
{
    newAttitude = false;
    return attitude;
}

__mavlink_global_position_int_t DataRetriever::getCompassValues()
{
    newCompass = false;
    return compassValues;
}

bool DataRetriever::newIMUAvailable()
{
    return newIMU;
}

bool DataRetriever::newAttitudeAvailable()
{
    return newAttitude;
}

bool DataRetriever::newCompassAvailable()
{
    return newCompass;
}

void DataRetriever::operator()()
{
    mavlink_message_t message;
    while(1)
    {
        if(readMAVLinkMessage(message))
        {
            if (message.msgid == MAVLINK_MSG_ID_SCALED_IMU2)
            {
                newIMU = true;
                mavlink_msg_scaled_imu2_decode(&message, &IMU2Values);
                imu.newReading(IMU2Values.xgyro,
                               IMU2Values.ygyro,
                               IMU2Values.zgyro,
                               IMU2Values.xacc,
                               IMU2Values.yacc,
                               IMU2Values.zacc,
                               0.03);

            }
            else if(message.msgid == MAVLINK_MSG_ID_ATTITUDE)
            {
                newAttitude = true;
                mavlink_msg_attitude_decode(&message, &attitude);
            }
            if(message.msgid == MAVLINK_MSG_ID_GLOBAL_POSITION_INT){
                newCompass = true;
                mavlink_msg_global_position_int_decode(&message, &compassValues);
                compass.newReading(compassValues.hdg);
            }
        }
        usleep(1000 * 30);
    }
}

bool DataRetriever::readMAVLinkMessage(mavlink_message_t& message)
{
    if (serialPort.peek() > 1)
    {
        mavlink_status_t status;
        char c;
        serialPort.readChar(&c);
        if (mavlink_parse_char(MAVLINK_COMM_0, c, &message, &status))
        {
            return true;
        }
    }
    return false;
}

//void DataRetriever::sendMessage(mavlink_message_t& message){
//unsigned char buffer[MAVLINK_NUM_NON_PAYLOAD_BYTES + message.len];
// int len = mavlink_msg_to_send_buffer(buffer, &message);
// serialPort.write(buffer,len);

//}
