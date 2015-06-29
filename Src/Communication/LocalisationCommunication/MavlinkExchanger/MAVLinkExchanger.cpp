#include "MAVLinkExchanger.h"
#include "SerialPort.h"
#include <iostream>

MAVLinkExchanger::MAVLinkExchanger(SerialPort& serialPort):
serialPort( serialPort )
{
}

void MAVLinkExchanger::enqueueMessage(PrioritisedMAVLinkMessage& message)
{
	sendQueue.push(message);
}

PrioritisedMAVLinkMessage MAVLinkExchanger::peek()
{
	if (receiveQueue.size())
	{
		return receiveQueue.top();
	}
	return PrioritisedMAVLinkMessage{};
}

int MAVLinkExchanger::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkExchanger::receiveQueueSize()
{
	return receiveQueue.size();
}

PrioritisedMAVLinkMessage MAVLinkExchanger::dequeueMessage()
{
	auto message = peek();
	receiveQueue.pop();
	return message;
}

void MAVLinkExchanger::loop()
{
	while (1)
	{
		receiveMessage();
		if (sendQueue.size())
		{
			sendMessage();
		}
	}
}

void MAVLinkExchanger::sendMessage()
{
	unsigned char buffer[MAVLINK_NUM_NON_PAYLOAD_BYTES + sendQueue.top().len];
	int len = mavlink_msg_to_send_buffer(buffer, &sendQueue.top());
	serialPort.writeData(buffer, len);
	sendQueue.pop();
}

void MAVLinkExchanger::receiveMessage()
{
	mavlink_status_t status;
	unsigned char c;
	do
	{
		serialPort.readData(&c, 1);
	}
	while (mavlink_parse_char(MAVLINK_COMM_0, c, &message, &status) == 0);
	receiveQueue.push(message);
}