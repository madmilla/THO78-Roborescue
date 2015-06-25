/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RosbeeDriver.cpp
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

#include "rosbeedriver.h"
//Needs to be defined in order to use math variables like PI, E, LOG, etc.
#define _USE_MATH_DEFINES
#include <cmath>
#include "encoderinterface.h"
#include "Waypoint.h"
#include <iostream> //heb misschien niet nodig

RosbeeDriver::RosbeeDriver(PropCom &nPropCom, PositionController& PC):
propCom{&nPropCom},
PC{&PC},
encoderLeft{&nPropCom,0},
encoderRight{&nPropCom,1},
speed{30}
{}	

void RosbeeDriver::stop(){
	propCom->setMotorSpeed(0, 0);
	propCom->setMotorSpeed(0, 1);
}

void RosbeeDriver::forward(signed char motorSpeed){
	propCom->setMotorSpeed(motorSpeed, 0);
	propCom->setMotorSpeed(motorSpeed, 1);
}

void RosbeeDriver::forward(signed char motor0Speed, signed char motor1Speed){
	propCom->setMotorSpeed(motor0Speed, 0);
	propCom->setMotorSpeed(motor1Speed, 1);
}

bool RosbeeDriver::drive(int distance){

	int distanceTraveled = 0;
	int deltaLeft = 0;
	int deltaRight = 0;
	int delta;

	int lspeed = 0;
	int rspeed = 0;

	for(int i = 0; i < speed*2; i++){
		if(i %2 == 0){
			lspeed++;
		}
		else{
			rspeed++;
		}
		forward(lspeed,rspeed);
	}

	encoderLeft.startCount();
	encoderRight.startCount();

	while(true){
		deltaLeft += encoderLeft.deltaCount();
		deltaRight += encoderRight.deltaCount();
		delta = deltaLeft - deltaRight;

		if(delta > 10 || delta < -10) continue;

		int nSpeed = speed - int(1.5*delta);

		std::cout << "Delta: " << delta << std::endl;
		std::cout << "Speed: " << nSpeed << std::endl;

		distanceTraveled = ((deltaLeft + deltaRight) / 2);
		if(distanceTraveled * 0.00773 >= distance/1000.0f){
			stop();
			break;
		}

		if(nSpeed < 0) nSpeed = 0;
		if(nSpeed > 127) nSpeed = 127;
		forward(nSpeed, speed);


		int distance = propCom->getDistance(1);
		std::cout << "Distance: " << distance << std::endl;

		if(distance < 40 && distance >= 0 ){
			stop();
			return false;
		}

		sleep(1);

	}
	return true;
}



void RosbeeDriver::rotate(int degrees){

	double totalDistance = 343 * M_PI; // mm
	double rotatingDistance = totalDistance * (std::abs(degrees)/360.0);

	if(degrees > 0){
		forward(-10, 10);
		PC->setMotorDirection(0, -1);
		PC->setMotorDirection(1, 1);
	}
	if(degrees < 0){
		forward(10, -10);
		PC->setMotorDirection(0, 1);
		PC->setMotorDirection(1, -1);
	}


	//std::cout << "Pi: " << pi << std::endl;
	//std::cout << "Rotating Distance: " <<  rotatingDistance << std::endl;
	//std::cout << "Pulses 0: " <<  numberOfPulsesWheel0 << std::endl;
	//std::cout << "Pulses 1: " <<  numberOfPulsesWheel1 << std::endl;

	encoderLeft.startCount();
	encoderRight.startCount();

	//double overshoot = 0;
	double distanceTraveled = 0;
	while(true){

		double deltaTraveld = (encoderLeft.deltaCount() + encoderRight.deltaCount()) / 2.0;

		if(deltaTraveld > 100 || deltaTraveld < 0) continue;

		distanceTraveled += (deltaTraveld * pulseToMilliMeter);
		//std::cout << "Distance Traveled: " <<  distanceTraveled << std::endl;


		if( distanceTraveled >= rotatingDistance - rotateAngleAdjustment){
			stop();
			break;
		}

		usleep(100*1000);
	}

	double deltaTraveld = (encoderLeft.deltaCount() + encoderRight.deltaCount()) / 2.0;
	distanceTraveled += (deltaTraveld * pulseToMilliMeter);

	//overshoot = 20 - (rotatingDistance - distanceTraveled);
	//std::cout << "Overshoot: " << overshoot << std::endl;
	PC->setMotorDirection(0, 1);
	PC->setMotorDirection(1, 1);
}


bool RosbeeDriver::driveToWaypoint(double x, double y){
	Waypoint waypoint{x,y};
	int distance = round(waypoint.getDistance());
	int angle = -round(waypoint.getAngle());

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "Distance: " << distance << std::endl;

	rotate(angle);
	return drive(distance);
}
