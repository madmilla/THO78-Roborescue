/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RosbeeProtocolHandler.h
* @date Created: 25-6-2015
*
* @author Nathan Schaaphuizen
* @version 1.0
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided$
* - Redistributions of source code must retain the above copyright notice, this list of conditions and th$
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and$
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors m$
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

#include "RosbeeClient.h"
#include "PositionController.h"
#include "RosbeeDriver.h"
#include <thread>
#include <roborescueV1/mavlink.h>


/// @brief Class to handle Rosbee commands.
///
/// This class parses the parameters from Mavlink and execute the
/// associated commands and send back the required response.
class RosbeeProtocolHandler {
private:
	RosbeeClient *rosClient;
	PositionController *posCont;
	RosbeeDriver *rosDriver;

	std::thread thread;
	//Helper function.
	//Will be ran by thread.
	void run();
	//Helper function.
	//Initiate connection with server.
	void init();
	//Helper function.
	//Drive the waypoint encoded in the Mavlink payload.
	void driveToWaypoint(const mavlink_command_long_t &payload);

public:
	/// @brief Create new RosbeeProtocol Handler object.
	///
	/// Creating a instance will run a new thread that automatically will handle incoming
	/// and outgoing messages.
	/// @param nRosClient Object used for communication with server.
	/// @param nPosContr Object used to control position.
	/// @param nRosDriver Object used to control the Rosbee.
	RosbeeProtocolHandler(RosbeeClient &nRosClient, PositionController &nPosContr, RosbeeDriver &nRosDriver);

};
