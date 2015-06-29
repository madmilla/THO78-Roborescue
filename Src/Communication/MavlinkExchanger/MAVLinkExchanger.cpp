#include "MAVLinkExchanger.h"
#include "TCPConnection.h"
#include "SerialConnection.h"
#include <iostream>

MAVLinkExchanger::MAVLinkExchanger(TCPConnection* tcpPort):
tcpPort( tcpPort )
{
	tcpPort->async_read_some(boost::asio::buffer(receiveBuffer), 
	std::bind(&MAVLinkExchanger::receiveMessage, 
	this, 
	std::placeholders::_1,
	std::placeholders::_2));
}

MAVLinkExchanger::MAVLinkExchanger(SerialConnection* serialPort):
serialPort(serialPort)
{
	serialPort->async_read_some(boost::asio::buffer(receiveBuffer), 
	std::bind(&MAVLinkExchanger::receiveMessage, 
	this, 
	std::placeholders::_1,
	std::placeholders::_2));
}

void MAVLinkExchanger::enqueueMessage(mavlink_message_t& message)
{
	sendQueue.push(message);
}

mavlink_message_t MAVLinkExchanger::peek()
{
	if (receiveQueue.size())
	{
		return receiveQueue.front();
	}
	return mavlink_message_t{};
}

int MAVLinkExchanger::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkExchanger::receiveQueueSize()
{
	return receiveQueue.size();
}

mavlink_message_t MAVLinkExchanger::dequeueMessage()
{
	auto message = peek();
	receiveQueue.pop();
	return message;
}

void MAVLinkExchanger::loop()
{
	while (1)
	{
		if (sendQueue.size())
		{
			sendMessage();
		}
	}
}

void MAVLinkExchanger::sendMessage()
{
	unsigned char buffer[MAVLINK_NUM_NON_PAYLOAD_BYTES + sendQueue.front().len];
	int len = mavlink_msg_to_send_buffer(buffer, &sendQueue.front());
	if(tcpPort != nullptr)
	{
		tcpPort->writeData(buffer, len);
	}
	else
	{
		serialPort->writeData(buffer, len);
	}
	sendQueue.pop();
}

void MAVLinkExchanger::receiveMessage(const boost::system::error_code &ec, std::size_t bytes_transferred)
{
	mavlink_status_t status;
	for(auto i = 0; i < bytes_transferred; ++i)
	{
		if(mavlink_parse_char(MAVLINK_COMM_0, receiveBuffer[i], &message, &status))
		{
			receiveQueue.push(message);
		}
	}
	if(tcpPort != nullptr)
	{
		tcpPort->async_read_some(boost::asio::buffer(receiveBuffer), 
		std::bind(&MAVLinkExchanger::receiveMessage, 
		this, 
		std::placeholders::_1,
		std::placeholders::_2));
	}
	else
	{
		serialPort->async_read_some(boost::asio::buffer(receiveBuffer), 
		std::bind(&MAVLinkExchanger::receiveMessage, 
		this, 
		std::placeholders::_1,
		std::placeholders::_2));
	}
	
}