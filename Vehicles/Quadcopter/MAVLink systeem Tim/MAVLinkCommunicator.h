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
	
	void Loop();

	void SendMessage(mavlink_message_t msg, char priority = 128);
	mavlink_message_t GetResponse(mavlink_message_t msg, char priority = 128);
	mavlink_message_t ReceiveMessage();

	int sendQueueSize();
	int receiveQueueSize();

	void stopThread();
	void abortThread();
private:
	PriorityMessage Peek();
	void Send(mavlink_message_t msg);
	bool Receive(mavlink_message_t & msg);

	SerialPort &serialPort;
	std::priority_queue<PriorityMessage> sendQueue;
	std::vector<mavlink_message_t> receiveQueue;

	bool stop = false;
	bool abort = false;
};
#endif

