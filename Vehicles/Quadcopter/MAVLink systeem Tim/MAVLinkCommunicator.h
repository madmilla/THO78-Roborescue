#ifndef _MAVLINKCOMMUNICATOR_H
#define _MAVLINKCOMMUNICATOR_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
#include "priority_mavlink_message_t.h"
#include <queue>
#include <vector>
#include <thread>
class SerialPort;

class MAVLinkCommunicator
{
public:
	explicit MAVLinkCommunicator(SerialPort& serialPort);
	void sendMessage(mavlink_message_t& message, char priority = 128);
	mavlink_message_t getMessage(mavlink_message_t& message, char priority = 128);
	bool receiveMessage(mavlink_message_t& message);
	void StopLoop();
	void AbortLoop();
	void Join();

private:

	void Loop();

	struct Compare
	{
		bool operator()(priority_mavlink_message_t & lhs, priority_mavlink_message_t & rhs) const{
			return lhs.getPriority() < rhs.getPriority();
		}
	};

	
	std::priority_queue<priority_mavlink_message_t, std::vector<priority_mavlink_message_t>, Compare> SendingQueue;
	std::vector<mavlink_message_t> ReceiveQueue;
	SerialPort& serialPort;

	std::thread *thread;
	bool stop = false;
	bool abort = false;

};
#endif