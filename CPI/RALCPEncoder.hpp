#pragma once
#include "Socket.hpp"
#include "mavlink_commands/udp_mavlink_commands/mavlink.h"

/// \author@ Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class@ RALCPEncoder
/// \brief The RALCPencoder functions as T section between the lidar and the rosbee for communication

class RALCPEncoder{
public:
	RALCPEncoder(Socket sock, int sid, int cid, int tsid, int tcid) : socket(sock), SYSTEMID(sid), COMPONENTID(cid), TARGET_SYSTEMID(tsid), TARGET_COMPONENTID(tcid){}
   /// \param@ Destination for the message to send to
	/// \param@ The right communication function
	/// \param@ Payload of the message this can contain 8 bytes, all data is shifted to the most left bit for documentation check the RCP wiki
	void send(COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS rcf, uint64_t payload);
	void send(COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS rcf, uint64_t payload);
	~RALCPEncoder(){}
private:
	mavlink_message_t msg;
	mavlink_ralcp_t packet;
	Socket socket;
	
	int SYSTEMID;
	int COMPONENTID;
	int TARGET_SYSTEMID;
	int TARGET_COMPONENTID;
};

