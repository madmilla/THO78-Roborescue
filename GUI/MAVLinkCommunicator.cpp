#include "MAVLinkCommunicator.h"
#include "../Vehicles/Dependencies/Serial/SerialPort.h"

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
		if (sendQueue.size())
		{
			PriorityMessage message = sendQueue.top();
			send(message);
			sendQueue.pop();
		}
		receive();
	}
}

void MAVLinkCommunicator::sendMessage(mavlink_message_t msg, char priority)
{
	sendQueue.push(PriorityMessage{ msg, priority });
}

PriorityMessage MAVLinkCommunicator::receiveMessage()
{
	PriorityMessage msg = peek();
	receiveQueue.pop();
	return msg;
}

int MAVLinkCommunicator::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkCommunicator::receiveQueueSize()
{
	return receiveQueue.size();
}

PriorityMessage MAVLinkCommunicator::peek()
{
	if (receiveQueue.size())
	{
		return receiveQueue.top();
	}
	else return PriorityMessage{};
}

void MAVLinkCommunicator::send(mavlink_message_t msg)
{
	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + msg.len];
	int len = mavlink_msg_to_send_buffer(buffer, &msg);
	serialPort.writeData(buffer, len);
}

void MAVLinkCommunicator::receive()
{
	PriorityMessage msg{};
	mavlink_status_t status;
	unsigned char c;
	serialPort.readData(&c, 1);
	if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
	{
		receiveQueue.push(msg);
	}
}
