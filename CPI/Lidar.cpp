/*
 * Lidar.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: hamza
 */
#include "Lidar.h"

Lidar::Lidar(bool equipmentStatus){}
virtual Lidar::~Lidar(){}

int * Lidar::getData(){
	mavlink_message_t msg;
	mavlink_getdata_t getDataMsg;

	mavlink_msg_getdata_decode(&msg, &getDataMsg);

	return static_cast<int[]>(getDataMsg.Payload);
}

int Lidar::getRpm(){
	mavlink_message_t msg;
	mavlink_getrpm_t getRpmMsg;

	mavlink_msg_getrpm_decode(&msg, &getRpmMsg);

	return static_cast<int>(getRpmMsg.Payload);
}

void Lidar::sendRpm(int rpm){

}

void Lidar::Start(int rpm){
	mavlink_message_t msg;
	mavlink_start_t startMsg;

	mavlink_msg_start_encode_chan(1, COMMAND_DESTINATION::LIDAR, 12, &msg, &startMsg);

	//Send via socket
	//sock->sendTo(&msg, 17, *ra);
}

void Lidar::Stop(){
	mavlink_message_t msg;
	mavlink_start_t stopMsg;
	stopMsg.Destination = COMMAND_DESTINATION::LIDAR;
	stopMsg.Function = ROSBEE_COMMAND_FUNCTIONS::STOP;
	stopMsg.Payload = 1;

	mavlink_msg_start_encode_chan(1, COMMAND_DESTINATION::LIDAR, 12, &msg, &stopMsg);

	//Send via socket
	//sock->sendTo(&msg, 17, *ra);
}

void Lidar::sendRosbeePositie(int postion[]){
	mavlink_message_t msg;
	mavlink_start_t rosbeeMsg;
	rosbeeMsg.Destination = COMMAND_DESTINATION::LIDAR;
	rosbeeMsg.Function = ROSBEE_COMMAND_FUNCTIONS::SENDROSBEEPOSITION;
	rosbeeMsg.Payload = postion;

	mavlink_msg_start_encode_chan(1, COMMAND_DESTINATION::LIDAR, 12, &msg, &rosbeeMsg);

	//Send via socket
	//sock->sendTo(&msg, 17, *ra);
}

void Lidar::sendRosbeeFlank(int degrees){
	mavlink_message_t msg;
	mavlink_start_t rosbeeMsg;
	rosbeeMsg.Destination = COMMAND_DESTINATION::LIDAR;
	rosbeeMsg.Function = ROSBEE_COMMAND_FUNCTIONS::SENDROSBEEFLANK;
	rosbeeMsg.Payload = degrees;

	mavlink_msg_start_encode_chan(1, COMMAND_DESTINATION::LIDAR, 12, &msg, &rosbeeMsg);

	//Send via socket
	//sock->sendTo(&msg, 17, *ra);
}
