/*!
* \class MAVLinkExchanger
*
* \brief
*
*
* \author
* \co-author
* \date April 2015
*/

#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "ExtendedMAVLinkMessage.h"

class SerialPort;

class MAVLinkExchanger
{
public:
	explicit MAVLinkExchanger(SerialPort& serialPort);
	void enqueueMessage(ExtendedMAVLinkMessage& message);
	ExtendedMAVLinkMessage dequeueMessage();
	ExtendedMAVLinkMessage peek();
	int sendQueueSize();
	int receiveQueueSize();
	void loop();
private:
	SerialPort& serialPort;
	std::priority_queue<ExtendedMAVLinkMessage> sendQueue;
	std::priority_queue<ExtendedMAVLinkMessage> receiveQueue;
	ExtendedMAVLinkMessage message;

	void sendMessage();
	void receiveMessage();
};
#endif