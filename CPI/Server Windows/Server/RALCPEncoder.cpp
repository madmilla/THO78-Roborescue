#include "RALCPEncoder.hpp"


void RALCPEncoder::send(COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS rcf, uint64_t payload){
	packet = {dest, rcf, payload};
	mavlink_msg_ralcp_encode(SYSTEMID, COMPONENTID, &msg, &packet);
	socket.send(&msg);
}