/*
 * PositionController.cpp
 *
 *  Created on: 18 jun. 2015
 *      Author: Edwin
 */

#include "PositionController.h"
#include "encoderinterface.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <thread>
#include <iostream>

PositionController::PositionController(PropCom* nPropCom):
m_angleOdometryEstimate{90},
m_posX{0},
m_posY{0},
lMotorDirection{1},
rMotorDirection{1},
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

void PositionController::setMotorDirection(int motorNr, int direction){
	if(direction == -1 || direction == 1){
		if(motorNr == 1){
			lMotorDirection = direction;
		}else if(motorNr == 0){
			rMotorDirection = direction;
		}
	}
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
	dLeft *= lMotorDirection;
	dRight *= rMotorDirection;
	//std::cout << "Sluisjes: " << dLeft << ", " << dRight << ", "<< m_angleOdometryEstimate << std::endl;
	if( dLeft < -5 ||  dLeft > 5 || dRight < -5 ||  dRight > 5) return;


    double dDistance,reDistance, leDistance, dAngle;
    reDistance = dRight * 0.0773;
    leDistance = dLeft * 0.0773;
    dDistance = ((leDistance + reDistance) / 2);
    dAngle = (reDistance * leDistance)/ 3.43;
    m_angleOdometryEstimate = m_angleOdometryEstimate + dAngle;

    //version 1
    //m_posX = m_posX + (dDistance * cos(m_angleOdometryEstimate));
    //m_posY = m_posY + (dDistance * sin(m_angleOdometryEstimate));

    //version 2
    //m_posX = m_posX + (dDistance * cos(m_angleOdometryEstimate / 2));
    //m_posY = m_posY + (dDistance * sin(m_angleOdometryEstimate / 2));

    //version 3
    m_posX = m_posX + ((dDistance * sin(reDistance - leDistance))/3.43);
    m_posY = m_posY + ((dDistance * cos(reDistance - leDistance))/3.43);




    m_dDistance += dDistance;

    //std::cout << "x= " << m_posX << " y=" << m_posY << " dd= " << dDistance << " d=" << m_dDistance << std::endl;


}
