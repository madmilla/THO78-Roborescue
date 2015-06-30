/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RosbeeProtocolHandler.cpp
* @date Created: 25-6-2015
*
* @author Nathan Schaaphuizen
* @version 1.0
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided$
* - Redistributions of source code must retain the above copyright notice, this list of conditions and th$
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and$
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors m$
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

#include "RosbeeProtocolHandler.h"
#include "RosbeeClient.h"
#include "PositionController.h"
#include "RosbeeDriver.h"
#include <thread>
#include <iostream>
#include <roborescueV1/mavlink.h>

RosbeeProtocolHandler::RosbeeProtocolHandler(RosbeeClient &nRosClient,
		PositionController &nPosContr,
		RosbeeDriver &nRosDriver
):
rosClient{&nRosClient},
posCont{&nPosContr},
rosDriver{&nRosDriver},
thread{&RosbeeProtocolHandler::run,this}
{
	//Separate the new thread from the current thread.
	thread.detach();
}


void RosbeeProtocolHandler::run(){
	//Mavlink command packet that will be filled.
	mavlink_command_long_t packet;
	//Start he handshake with server.
	init();
	//Run forever, there is no need for this thread to ever end.
	while(true){
		//Wait for a new incoming packet.
		//This function will block unit something arrives.
		rosClient->waitReceiveMessage(packet);
		//Check which command needs to be executed.
		//For now we only have one command.
		switch(packet.command){
		case ROSBEE_COMMAND_FUNCTIONS::SENDWAYPOINT:
			//Drive to waypoint.
			driveToWaypoint(packet);
			break;
		}
	}
}


void RosbeeProtocolHandler::init(){
	//Get the x offset.
	float newX =(posCont->getX());
	//Get the y offset.
	float newY = (posCont->getY());
	//Get the heading.
	float newAngle =(posCont->getAbsAngle());
	//Notify user we are waiting for the server.
	std::cout << "Starting handshake with server... ";
	//Flush the output so it shows on screen.
	//Beacuse we do not use a std::endl this will not always happen automatically.
	std::cout.flush();
	//Send the init packet.
	rosClient->sendInit(newX, newY, newAngle);
	//Mavlink packet that will be filled with the response.
	mavlink_command_long_t packet;
	//Wait until we receive a response:
	while(true){
		//Wait for incoming packet.
		//This function will block.
		rosClient->waitReceiveMessage(packet);
		//Check if it is the correct packet.
		if(packet.command == ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE ){
			//End the loop.
			//The packet does not contain anything useful we just need it as a
			//confirmation the server exists and is found.
			break;
		}
	}
	//Notify the user the handshake is complete.
	std::cout << "Done" << std::endl;
}


void RosbeeProtocolHandler::driveToWaypoint(const mavlink_command_long_t &payload){
	//Parse the x offset from the payload.
	float x = payload.param1;
	//Parse the x offset form the payload.
	float y = payload.param2;
	//Status indicating if we reached the waypoint successfully or not.
	float status = 0;
	//Notify the user we have received a waypoint.
	std::cout << "Waypoint received: " << x << ", " << y << std::endl;
	//Drive to the wayoint.
	//This function will block until the waypoint is reached for the ride is interrupted.
	//Then we check if the waypoint is  successfully reached or not.
	if(!rosDriver->driveToWaypoint(x,y)){
		//Set the status to 1 to indicate we did not reach the waypoint.
		status = 1;
	}
	//Get the new x coordinate.
	float newX = posCont->getX();
	//Get the new y coordinate.
	float newY = posCont->getY();
	//Get the new heading.
	float newAngle = posCont->getAbsAngle();
	//Notify the user we have reached the new position.
	//This is not nearly the end of the waypoint.
	std::cout << "Waypoint reached: (" << newX << ", " << newY << ") " << "r = " << newAngle <<std::endl;
	//Send the acknowledge back to the server and request a new waypoint.
	rosClient->requestWaypoint(newX, newY, newAngle, status);
}






