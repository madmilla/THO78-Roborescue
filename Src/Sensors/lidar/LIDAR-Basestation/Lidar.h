/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file lidar
* @date Created: 27-5-2015
*
* @author Rene Keijzer
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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



// class Lidar
// This class is used to initialize the Lidar and it contains the functions that the Lidar can recieve or send to the CPI
#ifndef __LIDAR__
#define __LIDAR__

#include <chrono>
#include "CPIBoundaryObject.h"
#include "roborescueV1/mavlink.h"
#include "UDPSocket.h"
#include "MessageQueue.h"
#include "RALCPEncoder.h"
#include "UDPRobot.h"
#include <tuple>
#include "Map.hpp"

class Lidar : public UDPRobot
{
public:
	// constructor to make a Lidar object (socket)
	// @param: Socket is used to listen to a specific socket
   Lidar(CPIUDPSocket * s);

	// initialize the Lidar 
	void init();
	void run() override;

	//! \brief Recieve line data from the lidar
	void recieveLine();

	//! \brief standard constructor
	//! \param[in] msg a reference to the mavlink message struct
	void recieveRpm();

	//! \brief standard constructor
	//! \param[in] rpm a reference to rpm to be set for the Lidar
	void sendRpm(int rpm);

	//! \brief start the lidar to scan
	void Start(int x, int y, int degrees);

	//! \brief stops the lidar with scanning
	void Stop();

	//! \brief sends the last knwon positon of the rosbee
	//! \param[in] postion a reference to the positon of the rosbee
	void sendRosbeePositie(int postion);

	//! \brief sends the current flank of the rosbee
	//! \param[in] dagrees a reference to the flank of the rosbee
	void sendRosbeeFlank(int degrees);

	void getData();

	// This function can finc out who the device is
	// @param: uint8_t dev this is the device
	void getDevice(uint8_t dev);
	void abort();
	int getId() override;


   MessageQueue<mavlink_message_t *> * getMessageQueue();
   MessageQueue<std::tuple<int, int, int, int>> * getLineDataQueue();

private:
   mavlink_command_long_t packet;
   friend class RobotManager;
   bool running = false;
   MessageQueue<std::tuple<int, int, int, int, int, int, int, LIDAR_COMMAND_FUNCTIONS, COMMAND_DESTINATION, int, int>> * outgoing;
   MessageQueue<std::tuple<int, int, int, int>> * LineDataQueue;
};
#endif
