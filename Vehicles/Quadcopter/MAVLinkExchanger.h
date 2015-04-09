#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "PrioritisedMAVLinkMessage.h"

class SerialPort;

class MAVLinkExchanger
{
public:
	explicit MAVLinkExchanger(SerialPort& serialPort);
	void enqueueMessage(PrioritisedMAVLinkMessage& message);
	PrioritisedMAVLinkMessage dequeueMessage();
	PrioritisedMAVLinkMessage peek();
	int sendQueueSize();
	int receiveQueueSize();
	void loop();
private:
	SerialPort& serialPort;
	std::priority_queue<PrioritisedMAVLinkMessage> sendQueue;
	std::priority_queue<PrioritisedMAVLinkMessage> receiveQueue;
	PrioritisedMAVLinkMessage message;

	void sendMessage();
	void receiveMessage();
};
#endif