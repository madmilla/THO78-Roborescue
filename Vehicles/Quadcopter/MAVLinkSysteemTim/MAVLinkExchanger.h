/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file           MAVLinkExchanger.h
* @date Created:  2015-04-08
*
*  @author  Tim Hasselaar
*  @author  Kjeld Perquin
*
*  @section LICENSE
*  License: newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
*     All rights reserved.
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

#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "PrioritisedMAVLinkMessage.h"
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"

class SerialPort;

class MAVLinkExchanger
{
public:

   /**
   * Create the MAVLink Communicator
   * @param serialPort, a reference to the serial port to which all the data has to be written.
   */
   explicit MAVLinkExchanger(SerialPort &serialPort);

   /**
   * The default deconstructor
   */
   ~MAVLinkExchanger();

   /**
   * The loop of this communication controller.
   * It will constantly check if there are messages to be sent, and if there are none,
   * the controller will try to receive a message.
   */
   void loop();

   /**
   * The enqueueMessage function.
   * This method will add the given prioritisedMessage to the sending queue.
   * @param msg, the message that has to be sent.
   */
   void enqueueMessage(PrioritisedMAVLinkMessage msg);

   /**
   * The dequeueMessage method. The controller will check the receive queue for received messages.
   * @return the PrioritisedMAVLinkMessage at the top of the queue.
   */
   PrioritisedMAVLinkMessage dequeueMessage();

   /**
   * The send queue size method.
   * @return the size of the queue with the messages that have to be sent.
   */
   int sendQueueSize() const;

   /**
   * The receive queue size method.
   * @return the size of the receive queue. Can be used to check if there are messages received that have to be handled.
   */
   int receiveQueueSize() const;

private:
   PrioritisedMAVLinkMessage peek() const;
   void send(mavlink_message_t msg);
   void receive();

   SerialPort &serialPort;
   std::priority_queue<PrioritisedMAVLinkMessage> sendQueue;
   std::priority_queue<PrioritisedMAVLinkMessage> receiveQueue;
};
#endif

