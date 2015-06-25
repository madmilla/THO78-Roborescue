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
	thread.detach();
}


void RosbeeProtocolHandler::run(){

	mavlink_command_long_t packet;
	init();

	while(true){
		rosClient->waitReceiveMessage(packet);

		switch(packet.command){
		case ROSBEE_COMMAND_FUNCTIONS::SENDWAYPOINT:
			driveToWaypoint(packet);
			break;
		}
		sleep(1);
	}
}


void RosbeeProtocolHandler::init(){
	float newX =(posCont->getX());
	float newY = (posCont->getY());
	float newAngle =(posCont->getAngle());

	std::cout << "Starting handshake with server... ";
	std::cout.flush();
	rosClient->sendInit(newX, newY, newAngle);

	mavlink_command_long_t packet;
	while(true){
		rosClient->waitReceiveMessage(packet);
		if(packet.command == ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE ){
			break;
		}
	}
	std::cout << "Done" << std::endl;

}


void RosbeeProtocolHandler::driveToWaypoint(const mavlink_command_long_t &payload){

	int x = payload.param1;
	int y = payload.param2;

	short status = 0;
	std::cout << "Waypoint received: " << x << ", " << y << std::endl;

	if(!rosDriver->driveToWaypoint(x,y)){
		status = 1;
	}

	short newX = static_cast<short>(posCont->getX());
	short newY = static_cast<short>(posCont->getY());
	short newAngle = static_cast<short>(posCont->getAngle());


	std::cout << "Waypoint reached: (" << newX << ", " << newY << ") " << "r = " << newAngle <<std::endl;

	rosClient->requestWaypoint(newX, newY, newAngle, status);

//	rosClient->sendMessage(ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, waypoint);
}






