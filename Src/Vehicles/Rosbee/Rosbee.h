/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Rosbee
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



/// \class Rosbee
/// \This class is used to initialize the rosbee and it contains the functions that the rosbee can recieve or send to the CPI
#ifndef __ROSBEE__
#define __ROSBEE__

#include <chrono>
#include "CPIBoundaryObject.h"
#include "roborescueV1/mavlink.h"
#include "UDPSocket.h"
#include "MessageQueue.h"
#include "RALCPEncoder.h"
#include "UDPRobot.h"
#include <tuple>


class Rosbee : public UDPRobot
{
public:
	/// \brief constructor to make a Rosbee object (socket)
	/// \param: Socket is used to listen to a specific socket
	Rosbee(CPIUDPSocket * s);

	/// \brief initialize the Rosbee 
	void init();

	/// \brief Run method of the rosbee boundary, this run reads it's queue's and handles it messsages
	void run() override;

	/// \brief this method checks if all devices are ready or not
	void getRequirementStatus();

	/// \brief This method starts a mission for a Rosbee
	void startMission();

	/// \brief This method sends waypoints to the Rosbee so he can ride to his destination
	/// \param: uint8_t x this parameter is used to send the x-axis of the new destination for the rosbee
	/// \param: uint8_t y this parameter is used to send the y-axis of the new destination for the rosbee
	void sendWaypoint(int x, int y);

	/// \brief This method can ask for a request at the CPI ( for now it only asks for new waypoints )
	void getRequest();

	/// \brief This method stops the mission of a Rosbee
	void stopMission();

	/// \brief This method cancells a mission of a Rosbee
	void abortMission();

	/// \brief This method sends a sonar interrupt to the CPI 
	void sonarInterrupt();

	/// \brief This method is needed for tests
	void sendAck();

	/// \brief This method is not used for now (maybe in the future)
	void BatteryStatus();

	/// \brief This method can finc out who the device is
	/// \param: uint8_t dev this is the device
    void getDevice(uint8_t dev);
    
    /// \brief aborts rosbee
    void abort();

    /// \brief returns unique identifier
    int getId() override;

    MessageQueue<mavlink_message_t *> * getMessageQueue();
	

private:


	friend class RobotManager;
	bool running = false;
	MessageQueue<std::tuple<int, int, int, int, int, int, int, ROSBEE_COMMAND_FUNCTIONS, COMMAND_DESTINATION, int, int>> * outgoing;
};
#endif
