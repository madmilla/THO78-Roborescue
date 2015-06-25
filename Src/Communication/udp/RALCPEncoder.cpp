#include "RALCPEncoder.h"


//void RALCPEncoder::send(COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS rcf, uint64_t payload){
//	rosbeePacket.Destination = dest;
//	rosbeePacket.Function = rcf;
	//rosbeePacket.Payload = payload;

	//mavlink_msg_rosbee_msg_encode(SYSTEMID, COMPONENTID, &msg, &packet);
//	socket->send(&msg);
//}

//void RALCPEncoder::send(COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS rcf, uint64_t payload){
//	lidarPacket.Destination = dest;
//	lidarPacket.Function = rcf;
	//lidarPacket.Payload = payload;
	
	//mavlink_msg_lidar_msg_encode(SYSTEMID, COMPONENTID, &msg, &packet);
//	socket->send(&msg);
//}


template <typename T>
void RALCPEncoder::send(COMMAND_DESTINATION dest, T function, int * payload){
	packet.Destination = dest;
	packet.Function = function;
	packet.Payload = payload;

	mavlink_msg_ralcp_encode(SYSTEMID, COMPONENTID, &msg, &packet);
	socket->send(&msg);
}


