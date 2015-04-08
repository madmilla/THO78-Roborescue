#include "MAVLinkExchanger.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>

MAVLinkExchanger::MAVLinkExchanger(SerialPort& serialPort):
serialPort{ serialPort }
{
}

void MAVLinkExchanger::enqueueMessage(ExtendedMAVLinkMessage& message)
{
	sendQueue.push(message);
}

ExtendedMAVLinkMessage MAVLinkExchanger::peek()
{
	if (receiveQueue.size())
	{
		return receiveQueue.top();
	}
	return ExtendedMAVLinkMessage{};
}

int MAVLinkExchanger::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkExchanger::receiveQueueSize()
{
	return receiveQueue.size();
}

ExtendedMAVLinkMessage MAVLinkExchanger::dequeueMessage()
{
	auto message = peek();
	receiveQueue.pop();
	return message;
}

void MAVLinkExchanger::loop()
{
	while (1)
	{
		//std::cout << "MELoop\n";

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