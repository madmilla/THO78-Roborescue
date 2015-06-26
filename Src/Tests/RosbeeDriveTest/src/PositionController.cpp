/*
 * PositionController.cpp
 *
 *  Created on: 18 jun. 2015
 *      Author: Edwin
 */

#include "../../PositionController.h"
#include "../../EncoderInterface.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <thread>
#include <iostream>

PositionController::PositionController(PropCom* nPropCom):
m_angleOdometryEstimate{90},
m_posX{0},
m_posY{0},
m_eLeft{nPropCom,0},
m_eRight{nPropCom,1},
thread{&PositionController::updatePosition,this}
{
    thread.detach();
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

float PositionController::getAngle(){
	return m_angleOdometryEstimate;
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
    double dDistance,reDistance, leDistance, dAngle;
    reDistance = dRight * 0.0773;
    leDistance = dLeft * 0.0773;
    dDistance = ((leDistance + reDistance) / 2);
    dAngle = (reDistance * leDistance)/ 3.43;
    m_angleOdometryEstimate = m_angleOdometryEstimate + dAngle;
    m_posX = m_posX + (dDistance * cos(m_angleOdometryEstimate));
    m_posY = m_posY + (dDistance * sin(m_angleOdometryEstimate));


//    if(dLeft != dRight){
//            dEncoder = dLeft - dRight;
//            dAngle = (dEncoder * 0.0773) / ((3.43 * 2 * M_PI) / 360);
//            m_posX = m_posX + ((1.715/2) * cos(dAngle));
//            m_posY = m_posY + ((1.715/2) * sin(dAngle));
//            m_angle += dAngle;
//    }else{
//            m_posX = cos(m_angle) * (dLeft * 0.0773);
//            m_posY = sin(m_angle) * (dLeft * 0.0773);
//    }
}
