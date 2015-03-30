/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 	mavlinkSubject.h
* @brief 	MavlinkSubject, allows for sending and receiving MAVLink messages.
* @date Created:	2015-03-23
*
*  @author	Daniël van den Berg
*  @author	Hylco Uding
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
*   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*   ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
*   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
*   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
*   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
*   OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef MAVLINKSUBJECT_H_INCLUDED
#define MAVLINKSUBJECT_H_INCLUDED

#include "mavlink/include/telemetryTest/mavlink.h"
#include "ioDevice.h"
#include <map>
#include <vector>
#include "mavlinkListener.h"
#include <iostream>
#include "mutex.h"

class MavlinkSubject {

	public:
		MavlinkSubject();
		/**
		*	@brief initiates the MavlinkSubject to listen to the specified IoDevice.
		*	@param ioDevice is the IoDevice to receive input from and write output to.
		*/
		void start(IoDevice *ioDevice);
		
		/**
		*	@brief stops the MavlinkSubject from listening to the IoDevice.
		*	@warning Not implemented, since this object isn't a thread because of PX4 compatibility. Would this become an actual thread, this method should be implemented.
		*/
		void stop();
		
		/**
		*	@brief registers a MavlinkListener.
		*	
		*	Use this function to register a MavlinkListener to this MavlinkSubject. All registered MavlinkListeners will get fired when a MAVLink message is received.
		*	@param ml the MavlinkListener to be registered.
		*/
		void addListener(MavlinkListener * ml);
		
		/**
		*	@brief sends a mavlink_message_t using the IoDevice specified in start()
		*	@warning This function is protected by a mutex, and will block until it was allowed to write to the IoDevice.
		*	@param msg the mavlink_message_t to send to the IoDevice
		*/
		void sendMessage(mavlink_message_t & msg);
		
		/**
		*	@brief updates the MavlinkSubject, making it receive input from the IoDevice
		*
		*	After calling this function the MavlinkSubject will poll the IoDevice to see if there is any data available. After receiving the data from this IoDevice, this function will trigger all registered MavlinkListener.
		*	@return true if the function was executed succesfully, false if the IoDevice was disconnected.
		*/
		bool update();
	
	private:
		std::vector <MavlinkListener *> list;
		IoDevice * SP;
		mutex sendMutex;
};

#endif