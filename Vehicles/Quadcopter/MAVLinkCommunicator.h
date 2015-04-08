#ifndef _MAVLINKCOMMUNICATOR_H
#define _MAVLINKCOMMUNICATOR_H
#include <queue>
#include "PriorityMessage.h"
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"

class SerialPort;

class MAVLinkCommunicator
{
public:
	explicit MAVLinkCommunicator(SerialPort &serialPort);
	~MAVLinkCommunicator();

	void loop();

	void sendMessage(mavlink_message_t msg, char priority = 128);
	PriorityMessage receiveMessage();

	int sendQueueSize();
	int receiveQueueSize();

	void stopThread();
	void abortThread();
private:
	PriorityMessage Peek();
	void send(mavlink_message_t msg);
	bool receive(mavlink_message_t & msg);

	SerialPort &serialPort;
	std::priority_queue<PriorityMessage> sendQueue;
	std::priority_queue<PriorityMessage> receiveQueue;

	bool stop = false;
	bool abort = false;
};
#endif

