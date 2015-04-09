#include "MAVLinkCommunicator.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>

MAVLinkCommunicator::MAVLinkCommunicator(SerialPort &serialPort) :
serialPort{ serialPort }
{
}

MAVLinkCommunicator::~MAVLinkCommunicator()
{
}

void MAVLinkCommunicator::loop()
{
	while (true)
	{
		//std::cout << "Hoi";
		if (sendQueue.size())
		{
			PriorityMessage message = Peek();
			send(message);
			sendQueue.pop();
		}
		PriorityMessage message{};
		if (receive(message))
		{
			receiveQueue.push(message);
		}
	}
}

void MAVLinkCommunicator::sendMessage(mavlink_message_t msg, char priority)
{
	sendQueue.push(PriorityMessage{ msg, priority });
}

PriorityMessage MAVLinkCommunicator::receiveMessage()
{
	if (receiveQueue.size())
	{
		return receiveQueue.top();
	}
	return PriorityMessage{};
}

int MAVLinkCommunicator::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkCommunicator::receiveQueueSize()
{
	return receiveQueue.size();
}

PriorityMessage MAVLinkCommunicator::Peek()
{
	if (sendQueue.size())
	{
		return sendQueue.top();
	}
	else return PriorityMessage{};
}

void MAVLinkCommunicator::send(mavlink_message_t msg)
{
	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + msg.len];
	int len = mavlink_msg_to_send_buffer(buffer, &msg);
	serialPort.writeData(buffer, len);
}

bool MAVLinkCommunicator::receive(mavlink_message_t & msg)
{
	mavlink_status_t status;
	unsigned char c;
	serialPort.readData(&c, 1);
	if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
	{
		return true;
	}
	return false;
}