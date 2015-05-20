#include "RALCPEncoder.hpp"


void RALCPEncoder::send(COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS rcf, uint64_t payload){
	packet.Destination = dest;
	packet.Function = rcf;
	packet.Payload = payload;
	mavlink_msg_ralcp_encode(SYSTEMID, COMPONENTID, &msg, &packet);
	socket->send(&msg);
}

void RALCPEncoder::send(COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS rcf, uint64_t payload){
	packet.Destination = dest;
	packet.Function = rcf;
	packet.Payload = payload;
	mavlink_msg_ralcp_encode(SYSTEMID, COMPONENTID, &msg, &packet);
	socket->send(&msg);
}