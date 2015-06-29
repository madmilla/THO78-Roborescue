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

RosbeeDriver::RosbeeDriver(PropCom &nPropCom, PositionController& PC):
propCom{&nPropCom},
PC{&PC},
encoderLeft{&nPropCom,0},
encoderRight{&nPropCom,1},
speed{30},
turnSpeed{10}	
{}	

void RosbeeDriver::stop(){
	//Set the motor speed for the left motor to zero.
	//This will make the  motor  stop.
	propCom->setMotorSpeed(0, 0);
	//Set the motor speed for the right motor to zero.
	//This will make the  motor  stop.
	propCom->setMotorSpeed(0, 1);
}

void RosbeeDriver::forward(signed char motorSpeed){
	//Set the motor speed for the left motor to motorSpeed.
	propCom->setMotorSpeed(motorSpeed, 0);
	//Set the motor speed for right left motor to motorSpeed.
	propCom->setMotorSpeed(motorSpeed, 1);
}

void RosbeeDriver::forward(signed char motor0Speed, signed char motor1Speed){
	//Set the motor speed for the left motor to motor0Speed.
	propCom->setMotorSpeed(motor0Speed, 0);
	//Set the motor speed for right left motor to motor1Speed.
	propCom->setMotorSpeed(motor1Speed, 1);
}

bool RosbeeDriver::drive(int distance){
	PC->resetDDistance();
	PC->forward();
	int distanceTraveled = 0;
	int deltaLeft = 0;
	int deltaRight = 0;
	int delta;
	//Left motor speed.
	int lspeed = 0;
	//Right motor speed.
	int rspeed = 0;
	//Setting two monitors to equivalent speed takes time. This means that one motor
	//will spin up first while the seconds follows. This will cause the Rosbee to turn.
	//To negate the problem the two motors take little steps each other turn.
	for(int i = 0; i < (speed*2); i++){
		//Check if it is the left turn.
		if(i %2 == 0){
			//Up the left motor speed.
			lspeed++;
		}
		//If not  it is the right turn.
		else{
			//Up the right motor speed.
			rspeed++;
		}
		//Send the new motor speed to the Rosbee.
		forward(lspeed,rspeed);
	}
	//Start new encoder counters.
	encoderLeft.startCount();
	encoderRight.startCount();
	//Start the forward loop:
	while(true){
		//Get the new delta values.
		deltaLeft += encoderLeft.deltaCount();
		deltaRight += encoderRight.deltaCount();
		delta = deltaLeft - deltaRight;
		//Filter large values.
		//These are errors.
		if(delta > 10 || delta < -10) continue;
		//Get the new speed for the left weel;
		int nSpeed = speed - int(1.5*delta);
		//Get the distance traveled.
		distanceTraveled = PC->getDDistance();
		if(distanceTraveled >= distance){
			stop();
			break;
		}
		//Normalize speed so it fits in range from 0 to 127;
		if(nSpeed < 0) nSpeed = 0;
		if(nSpeed > 127) nSpeed = 127;
		//Update speed.
		forward(nSpeed, speed);
		//Get the the distance returned from the sensor upfront the Rosbee.
		int distance = propCom->getDistance(1);
		//Check if there is a object 50 cm or closer the the Rosbee.
		if(distance < 50 && distance >= 0 ){
			stop();
			return false;
		}
		//Sleep for 1 second.
		sleep(1);

	}
	return true;
}

void RosbeeDriver::rotate(int degrees){
	//Check it degrees is positive
	//This means we will turn clockwise.
	if(degrees > 0){
		//Start turing cw.
		forward(turnSpeed, -turnSpeed);
		//Tell the position controller we are rotating cw.
		PC->rotating(true);
	}
	//Check it degrees is negative.
	//This means we will turn counter clockwise.
	if(degrees < 0){
		//Start turing ccw.
		forward(-turnSpeed, turnSpeed);
		//Tell the position controller we are rotating ccw.
		PC->rotating(false);
	}
	//Set the last angle.
	//This is needed to calc the new delta ange.
	float lastAngle = PC->getTotalAngle();
	//Total angel we turned so far.
	float angle = 0;
	//Ange we turned since last check.
	float dAngle;
	//Make the the degrees positive (incase it was negative).
	//This is needed so we can compare it  the  the angel later on.
	degrees = std::abs(degrees);
        //Start the turning loop:
	while(true){
                //Get the new angle.
		float newTotalAngle = PC->getTotalAngle() ;
		//Get the delta angle since last iteration.
		dAngle = std::abs(newTotalAngle - lastAngle);
		//Add the new delata to the total.
		angle += dAngle;
		//Set the last angle to the new angel.
		//Needed to create a new correct delta on the following iteration.
		lastAngle = newTotalAngle;
		//Check if we turned far enough.
		if(angle >= degrees){
			//Stop moving.
			stop();
			//End the loop.
			break;
		}
		//Sleep for 50 ms.
		usleep(50*1000);
	}
}


bool RosbeeDriver::driveToWaypoint(double x, double y){
	//Create a new waypoint object to do some calculations for us.
	Waypoint waypoint{x,y};
	//Get the distance the Rosbee needs to drive and make a nice round number.
	int distance = round(waypoint.getDistance());
	//Get the angle the Rosbee needs to turn round number.
	int angle = round(waypoint.getAngle());
	//Start rotating.
	rotate(angle);
	//Start driving and return the results.
	return drive(distance);
}
