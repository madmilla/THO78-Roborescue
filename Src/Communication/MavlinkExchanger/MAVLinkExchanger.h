#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "PrioritisedMAVLinkMessage.h"

class DataPort;

class MAVLinkExchanger
{
public:
	explicit MAVLinkExchanger(DataPort& dataPort);
	void enqueueMessage(PrioritisedMAVLinkMessage& message);
	PrioritisedMAVLinkMessage dequeueMessage();
	PrioritisedMAVLinkMessage peek();
	int sendQueueSize();
	int receiveQueueSize();
	void loop();
private:
	DataPort& dataPort;
	std::priority_queue<PrioritisedMAVLinkMessage> sendQueue;
	std::priority_queue<PrioritisedMAVLinkMessage> receiveQueue;
	PrioritisedMAVLinkMessage message;

	void sendMessage();
	void receiveMessage();
};
#endif