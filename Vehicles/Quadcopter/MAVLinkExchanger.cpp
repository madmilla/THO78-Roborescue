#include "MAVLinkExchanger.h"
#include "../Dependencies/Serial/SerialPort.h"

MAVLinkExchanger::MAVLinkExchanger(SerialPort &serialPort) :
serialPort{ serialPort }
{
}

MAVLinkExchanger::~MAVLinkExchanger()
{
}

void MAVLinkExchanger::loop()
{
	while (true)
	{
		if (sendQueue.size())
		{
			PrioritisedMAVLinkMessage message = sendQueue.top();
			send(message);
			sendQueue.pop();
		}
		receive();
	}
}

void MAVLinkExchanger::enqueueMessage(PrioritisedMAVLinkMessage msg)
{
	sendQueue.push(msg);
}

PrioritisedMAVLinkMessage MAVLinkExchanger::dequeueMessage()
{
	PrioritisedMAVLinkMessage msg = peek();
	receiveQueue.pop();
	return msg;
}

int MAVLinkExchanger::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkExchanger::receiveQueueSize()
{
	return receiveQueue.size();
}

PrioritisedMAVLinkMessage MAVLinkExchanger::peek()
{
	if (receiveQueue.size())
	{
		return receiveQueue.top();
	}
	else return PrioritisedMAVLinkMessage{};
}

void MAVLinkExchanger::send(mavlink_message_t msg)
{
	auto buffer = new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES + msg.len];
	int len = mavlink_msg_to_send_buffer(buffer, &msg);
	serialPort.writeData(buffer, len);
}

void MAVLinkExchanger::receive()
{
	PrioritisedMAVLinkMessage msg{};
	mavlink_status_t status;
	unsigned char c;
	serialPort.readData(&c, 1);
	if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
	{
		receiveQueue.push(msg);
	}
}