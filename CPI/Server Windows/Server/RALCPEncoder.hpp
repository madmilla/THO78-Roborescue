#pragma once
#include "Socket.hpp"
#include "..\..\mavlink_commands\mavlink_commands\mavlink.h"
class RALCPEncoder
{
public:
	RALCPEncoder(Socket sock, int sid, int cid, int tsid, int tcid) : socket(sock), SYSTEMID(sid), COMPONENTID(cid), TARGET_SYSTEMID(tsid), TARGET_COMPONENTID(tcid){}
	void send(COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS rcf, uint64_t payload);
	~RALCPEncoder();
private:
	mavlink_message_t msg;
	mavlink_ralcp_t packet;
	Socket socket;
	
	int SYSTEMID;
	int COMPONENTID;
	int TARGET_SYSTEMID;
	int TARGET_COMPONENTID;
};

