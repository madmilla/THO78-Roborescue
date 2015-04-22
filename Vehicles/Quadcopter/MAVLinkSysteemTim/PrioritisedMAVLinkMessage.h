/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file            MAVLinkCommunicator.h
* @date Created:   2015-04-08
*
*  @author  Tim Hasselaar
*  @author  Kjeld Perquin
*
*  @section LICENSE
*  License: newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
*  All rights reserved.
*
*
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*  - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
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

#ifndef _PRIORITESMAVLINKMESSAGE_H
#define _PRIORITESMAVLINKMESSAGE_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"

const char _LOW_PRIORITY = 64; // Right in between 128 and 0.
const char _NORMAL_PRIORITY = 128; // The middle priority (half of 256)
const char _HIGH_PRIORITY = 192; // Right in the middle of 128 and 256
const char _EXTREME_PRIORITY = 256; // The maximum priority

class PrioritisedMAVLinkMessage : public mavlink_message_t
{
public:

   /**
   * The default constructor of a PrioritisedMAVLinkMessage.
   * @param msg, the mavlink message which contains all the data.
   * @param priority, the priority that this message has. Higher priority messages will be placed higher in the queue,
   *	and will thus be handled at a more timely manner than lower priority messages.
   */
   explicit PrioritisedMAVLinkMessage(mavlink_message_t & msg, char priority);

   /**
   * The constructor used for received messages.
   * Because a received message doesnt receive a priority from the quadcopter, there is a constructor with only the mavlink message as paramter.
   * The priority of this message will be determined using the message id. Heartbeats, for example, will be less important than a channel override.
   * @param msg, the mavlink message containing all the data.
   */
   PrioritisedMAVLinkMessage(mavlink_message_t & msg);

   /**
   * The constructor with no parameters.
   * This constructor will be used when an empty priority message is created.
   * This can be used when a message has to be returned, but there is nothing to return.
   */
   PrioritisedMAVLinkMessage();

   /**
   * The default deconstructor
   */
   ~PrioritisedMAVLinkMessage();

   /**
   * The less than operator for comparing two priority messages.
   * This operator is required to use a priority queue.
   * This method will compare the priority variables of the first and second message.
   * @param lhs, the first priority message that will be compared.
   * @param rhs, the second priority message that will be compared.
   * @return wether or not the priority of the first message is smaller than the priority of the second message.
   */
   friend bool operator<(const PrioritisedMAVLinkMessage & lhs, const PrioritisedMAVLinkMessage & rhs);

   /**
   * This is the get-function for the priority of the priority message.
   * @return the priority of a priority message.
   */
   char getPriority() const;

private:
   char priority;
};
#endif

