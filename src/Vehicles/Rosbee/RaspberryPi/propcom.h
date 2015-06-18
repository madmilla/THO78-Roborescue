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
#include "ParallaxPropellerProtocol.h"
/**
 * @brief The PropCom class
 */
class PropCom {
public:
    /**
     * @brief PropCom Constructor
     * @param port USB port that is used to send and recieve data
     */
    PropCom(std::string port);
    /**
     * @brief PropCom destructor
     */
    ~PropCom();

    /**
     * @brief Opens a serial port.
     * @param port USB port that is used to send and recieve data.
     */
    void initiate(std::string port);
    /**
     * @brief Sends 2 bytes over the serial port.
     * @param command first byte that is send over the serial port.
     * @param value second byte that is send over the serial port.
     */
    void sendData(unsigned char command, unsigned char value);
    /**
     * @brief Reads data from the serial port.
     * @param command Command that is send over the serial port.
     * @param returnedBytes The amount of bytes that are returned.
     * @return The data that is returned depends on the send command.
     */
    std::vector<unsigned char> readData(unsigned char command, int returnedBytes);
    /**
     * @brief Configures how fast RoSBee brakes.
     * @param speed Specifies the new brake speed.
     * @param motorNr The motor that is to be configured.
     */
    void setBrakeSpeed(signed char speed, int motorNr);
    /**
     * @brief Sets the motor speed to a new value.
     * @param speed The new motor speed.
     * @param motorNr The motor that is to be configured. 1 selects the right
     *  motor, 0 selects the left motor
     */
    void setMotorSpeed(signed char speed, int motorNr);
    /**
     * @brief Returns the current firmware version
     * @return The firmware version
     */
    int getFirmwareVersion();
    /**
     * @brief Returns errors.
     * @return 0 if there are no errors. If there are errors a
     *  value between 0 and 50 wil be returned
     */
    int getError();
    /**
     * @brief Returns the current count of the encoder.
     * @param Specifies the motor whose encoder wil be read.
     * @return The current count of the encoder on the specified motor.
     */
    int getPulseCount(int motorNr);
    /**
     * @brief Returns the current pulse speed of the encoder.
     * @param motorNr Specifies the motor whose encoder wil be read.
     * @return The current pulse speed of the encoder on the specified motor.
     */
    int getPulseSpeed(int motorNr);
    /**
     * @brief Returns a reading of an ultrasonic sensor.
     * @param Specifies which ultrasonic sensor wil be read from.
     * @return The reading of the specified ultrasonic sensor.
     */
    int getDistance(int ultraSonicSensorNr);

private:
    /**
     * @brief The serial port that is opened.
     */
    LibSerial* com;
};


#endif
