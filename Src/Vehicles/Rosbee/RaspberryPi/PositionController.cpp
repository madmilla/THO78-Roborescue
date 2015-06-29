/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PositionController.cpp
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
#include "PositionController.h"
#include "encoderinterface.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <thread>
#include <iostream>

PositionController::PositionController(PropCom* nPropCom):
    m_angleOdometryEstimate{0},
    m_totalAngle{0},
    m_dDistance{0},
    m_posX{0},
    m_posY{0},
    dir{1},
    isRotating{false},
    isForward{false},
    m_eLeft{nPropCom,0},
    m_eRight{nPropCom,1},
    thread{&PositionController::updatePosition,this}
{
    thread.detach();
}

float PositionController::getDDistance(){
    return m_dDistance;
}

void PositionController::resetDDistance(){
    m_dDistance = 0;
}

void PositionController::reset(){
    m_posX = 0;
    m_posY = 0;
}


float PositionController::getX(){
    return m_posX;
}

float PositionController::getY(){
    return m_posY;
}

float PositionController::getAbsAngle(){
    return m_angleOdometryEstimate;
}

float PositionController::getTotalAngle(){
    return m_totalAngle;
}

void PositionController::updatePosition(){
    m_eLeft.startCount();
    m_eRight.startCount();

    while(1){
        usleep(1000 * 33);
        odometry(m_eLeft.deltaCount(),m_eRight.deltaCount());
    }
}

void PositionController::odometry(int dLeft, int dRight){
    if( dLeft < -5 ||  dLeft > 5 || dRight < -5 ||  dRight > 5) return;

    if(isForward ){
        double dDistance,reDistance, leDistance, dAngle;
        // 7.73 is the amount of distance traveled for each encoder count in millimeters
        reDistance = dRight * 7.73;
        leDistance = dLeft * 7.73;
        dDistance = ((leDistance + reDistance) / 2);
        // 343 is the track of the Rosbee in millimeters
        dAngle = (reDistance - leDistance)/ 343;
        //m_totalAngle += std::abs(dAngle);


        //version 1
        //m_posX = m_posX + (dDistance * cos(m_angleOdometryEstimate));
        //m_posY = m_posY + (dDistance * sin(m_angleOdometryEstimate));

        //version 2
        //m_posX = m_posX + (dDistance * cos(m_angleOdometryEstimate / 2));
        //m_posY = m_posY + (dDistance * sin(m_angleOdometryEstimate / 2));

        //version 3
        // m_posX = m_posX + ((dDistance * sin(reDistance - leDistance))/343);
        // m_posY = m_posY + ((dDistance * cos(reDistance - leDistance))/343);

        //version 4
        m_posX = m_posX + (dDistance * sin((m_angleOdometryEstimate / (180/M_PI))+ (dAngle/2)));
        m_posY = m_posY + (dDistance * cos((m_angleOdometryEstimate / (180/M_PI)) + (dAngle/2)));

        m_angleOdometryEstimate = m_angleOdometryEstimate + (dAngle * (180 /M_PI));
        if(m_angleOdometryEstimate >=360){
            m_angleOdometryEstimate -= 360;
        }
        if(m_angleOdometryEstimate < 0){
            m_angleOdometryEstimate += 360;
        }

        m_dDistance += dDistance;
        //std::cout << "x= " << m_posX << " y=" << m_posY << " dd= " << dDistance << " d=" << m_dDistance << " r= " << m_angleOdometryEstimate << std::endl;
    }

    if(isRotating){
        double leDistance, dAngle;
        leDistance = dLeft * 7.73 * dir;
        dAngle = ((leDistance)/(343*M_PI)) * 360;
        m_angleOdometryEstimate += dAngle;
        m_totalAngle += std::abs(dAngle);

        if(m_angleOdometryEstimate >=360){
            m_angleOdometryEstimate -= 360;
        }
        if(m_angleOdometryEstimate < 0){
            m_angleOdometryEstimate += 360;
        }

    }
}

void PositionController::forward(){
    isRotating = false;
    isForward = true;
}

void PositionController::rotating(bool isClockwise){
    if(isClockwise){
        dir = 1;
    }
    else{
        dir = -1;
    }

    isRotating = true;
    isForward = false;
}

