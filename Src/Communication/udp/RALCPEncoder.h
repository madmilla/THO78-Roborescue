/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RALCPEncoder
* @date Created: 27-5-2015
*
* @author Rene Keijzer
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
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





#ifndef __RALCPENCODER__
#define __RALCPENCODER__
#include "Socket.h"
#include <iostream>
#include <tuple>
#include "roborescueV1/mavlink.h"

/// \class@ RALCPEncoder
/// \brief The RALCPencoder functions as T section between the lidar and the rosbee for communication

class RALCPEncoder{
public:
	RALCPEncoder(CPISocket * sock, int sid, int cid, int tsid, int tcid) : socket(sock), SYSTEMID(sid), COMPONENTID(cid), TARGET_SYSTEMID(tsid), TARGET_COMPONENTID(tcid){}

	template <typename ... Args>
	void send(Args ...args){
		packet = mavlink_command_long_t{std::forward<Args>(args) ...};
		mavlink_msg_command_long_encode(SYSTEMID, COMPONENTID, &msg, &packet);
		socket->send(&msg);
	}


	~RALCPEncoder(){}
private:
	mavlink_message_t msg;
	mavlink_command_long_t packet;
	CPISocket * socket;
	
	int SYSTEMID;
	int COMPONENTID;
	int TARGET_SYSTEMID;
	int TARGET_COMPONENTID;
};

#endif