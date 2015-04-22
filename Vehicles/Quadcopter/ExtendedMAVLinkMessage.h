/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			ExtendedMAVLinkMessage.h
* @date Created:	-
*
*  @author	-
*  @author	-
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms,
*	with or without modification, are permitted provided that
*	the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice,
*	  this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice,
*	  this list of conditions and the following disclaimer in the documentation
*	  and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht
*	  nor the names of its contributors may be used to endorse or
*	  promote products derived from this software without
*	  specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
*	BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
*	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*	IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
*   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
*	OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
*	OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#ifndef _EXTENDEDMAVLINKMESSAGE_H
#define _EXTENDEDMAVLINKMESSAGE_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
#include <array>
#include <chrono>

const std::array<uint8_t, 1> MEDIUM_PRIORITIES = { 
	MAVLINK_MSG_ID_HEARTBEAT };
const std::array<uint8_t, 1> HIGH_PRIORITIES = { 
	MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE };
const std::array<uint8_t, 0> EXTREME_PRIORITIES = {};

class ExtendedMAVLinkMessage : public mavlink_message_t
{
public:
	explicit ExtendedMAVLinkMessage(const mavlink_message_t& baseMessage);
	ExtendedMAVLinkMessage();

	friend bool operator<(
		const ExtendedMAVLinkMessage& lhs, 
		const ExtendedMAVLinkMessage& rhs);

	enum class Priority
	{
		LOW_PRIORITY,
		MEDIUM_PRIORITY,
		HIGH_PRIORITY,
		EXTREME_PRIORITY
	};
	Priority getPriority() const;
	friend std::ostream& operator<<(
		std::ostream& stream, 
		const Priority& priority);
private:
	std::chrono::system_clock::time_point timeCreated;
};
#endif