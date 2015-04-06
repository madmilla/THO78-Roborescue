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
		receiveMessage();
		if (sendQueue.size())
		{
			sendMessage();
		}
	}
}

void MAVLinkExchanger::sendMessage()
{
	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + sendQueue.top().len];
	int len = mavlink_msg_to_send_buffer(buffer, &sendQueue.top());
	serialPort.writeData(buffer, len);
	std::cout << "Sent message with priority: " << sendQueue.top().getPriority() << std::endl;
	sendQueue.pop();
}

void MAVLinkExchanger::receiveMessage()
{
	mavlink_status_t status;
	char c;
	do
	{
		serialPort.readData(&c, 1);
	}
	while (mavlink_parse_char(MAVLINK_COMM_0, c, &message, &status) == 0);
	//std::cout << "Received message with priority: " << message.getPriority() << std::endl;
	receiveQueue.push(message);
}