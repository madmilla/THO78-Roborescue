#include "Rosbee.hpp"


void Rosbee::init(){
	mavlink_ras
	mavlink_init_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::INIT, 0 };
	mavlink_msg_//(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);
}

void Rosbee::getRequirementStatus(){
	mavlink_getequipmentstatus_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::GETEQUIPMENTSTATUS, 0 };
	mavlink_msg_getequipmentstatus_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);
}

void Rosbee::startMission(){
	mavlink_startmission_t packet= { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::STARTMISSION, 0 };
	mavlink_msg_startmission_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);

}

void Rosbee::sendWaypoint(uint8_t x, uint8_t y){
	mavlink_sendwaypoint_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::SENDWAYPOINT, uint16_t((x << 8 )| y) };
	mavlink_msg_sendwaypoint_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);

}

void Rosbee::getRequest(){
	mavlink_getrequest_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::GETREQUEST, 0 };
	mavlink_msg_getrequest_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);
}

void Rosbee::stopMission(){
	mavlink_stopmission_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::STOPMISSION, 0 };
	mavlink_msg_stopmission_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);
}

void Rosbee::abortMission(){
	mavlink_abortmission_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::ABORTMISSION, 0 };
	mavlink_msg_abortmission_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);

}

void Rosbee::sonarInterrupt(){
	mavlink_sonarinterrupt_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::SONARINTERRUPT, 0 };
	mavlink_msg_sonarinterrupt_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);

}

void Rosbee::sendAck(){
	mavlink_acknowledge_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, 0 };
	mavlink_msg_acknowledge_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);


}

void Rosbee::BatteryStatus(){
	mavlink_batterystatus_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::BATTERYSTATUS, 0 };
	mavlink_msg_batterystatus_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);
}


void Rosbee::getDevice(uint8_t dev){
	mavlink_getdevice_t packet = { COMMAND_DESTINATION::ROSBEE, ROSBEE_COMMAND_FUNCTIONS::GETDEVICE, dev };
	mavlink_msg_getdevice_encode(SYSTEMID, COMPONENTID, &message, &packet);
	socket.send(&message);
}