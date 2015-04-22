#include "Rosbee.hpp"


void Rosbee::init(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::ROSBEE_INIT, 0);
}

void Rosbee::getRequirementStatus(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::GETEQUIPMENTSTATUS, 0);
}

void Rosbee::startMission(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::STARTMISSION, 0);

}

void Rosbee::sendWaypoint(uint8_t x, uint8_t y){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::SENDWAYPOINT, uint64_t((x << 54 ) | (y << 46)));
}

void Rosbee::getRequest(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::ROSBEE_GETREQUEST, 0);
}

void Rosbee::stopMission(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::STOPMISSION, 0);
}

void Rosbee::abortMission(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::ABORTMISSION, 0);

}

void Rosbee::sonarInterrupt(){

}

void Rosbee::sendAck(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, 0);
}

void Rosbee::BatteryStatus(){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::BATTERYSTATUS, 0);
}


void Rosbee::getDevice(uint8_t dev){
	encoder->send(COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::GETDEVICE, uint64_t(dev << 54));
}