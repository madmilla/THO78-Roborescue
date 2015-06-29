/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PositionController.h
* @date Created: 26-6-2015
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
#ifndef POSITIONCONTROLLER_H_
#define POSITIONCONTROLLER_H_

#include "encoderinterface.h"
#include "propcom.h"
#include <thread>
/**
 * @brief The PositionController class
 */
class PositionController {
public:
    /**
     * @brief PositionController constructor
     * @param nPropCom is the propeller communicator.
     */
    explicit PositionController(PropCom* nPropCom);
    /**
     * @brief Returns the X position of the Rosbee
     * @return returns the X position of the Rosbee
     */
    float getX();
    /**
     * @brief returns the Y position of the Rosbee
     * @return returns the Y position of the Rosbee
     */
    float getY();
    /**
     * @brief Returns the accumulated angle.
     * @return returns the accumulated change of angle.
     */
    float getTotalAngle();
    /**
     * @brief Returns an absolute angle
     * @return returns an angle between 0 and 360 degrees
     */
    float getAbsAngle();
    /**
     * @brief Returns the change in distance
     * @return returns the measured change of distance
     */
    float getDDistance();
    /**
     * @brief Resets the change in distance
     *
     * This function resets the measured change of distance
     */
    void resetDDistance();
    /**
     * @brief Resets the XY position
     *
     * This function resets the position X and Y values.
     */
    void reset();
    /**
     * @brief Updates the position
     *
     * Is the main loop that applies all the other functions to calculate the current position
     * and heading.
     */
    void updatePosition();
    /**
     * @brief Applies odometry
     *
     * This function calculates how far the Rosbee has traveled aswel as how much
     * its angle has changed by applying odometry to the encoder readings.
     * @param dLeft is the change in encoder count of the left wheel.
     * @param dRight is the change in encoder count of the right wheel.
     */
    void odometry(int dLeft, int dRight);
    /**
     * @brief Sets the motors to drive forward.
     */
    void forward();
    /**
     * @brief Rotates the Rosbee.
     *
     * This function sets the state of the Rosbee to rotating. The direction of the rotation is given through
     * isClockwise
     * @param isClockwise defines wether the Rosbee is turning Clockwise or not.
     */
    void rotating(bool isClockwise);


private:
    //Angle estimated thourhg odometry
    float m_angleOdometryEstimate;
    // angle that is used to determine wether the Rosbee has succesfully turned during rotaion
    float m_totalAngle;
    //delta distance
    float m_dDistance;

    float m_posX;
    float m_posY;

    int dir;

    bool isRotating;
    bool isForward;

    EncoderInterface m_eLeft;
    EncoderInterface m_eRight;

    std::thread thread;
};

#endif /* POSITIONCONTROLLER_H_ */
