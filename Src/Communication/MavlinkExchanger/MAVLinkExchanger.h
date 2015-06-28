#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "roborescueV1/mavlink.h"
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>

class TCPConnection;

class MAVLinkExchanger
{
public:
	explicit MAVLinkExchanger(TCPConnection& dataPort);
	void enqueueMessage(mavlink_message_t& message);
	mavlink_message_tdequeueMessage();
	mavlink_message_tpeek();
	int sendQueueSize();
	int receiveQueueSize();
	void loop();
private:
	TCPConnection& dataPort;
	std::queue<mavlink_message_t> sendQueue;
	std::queue<mavlink_message_t> receiveQueue;
	mavlink_message_t message;

	unsigned char sendBuffer[256];
	unsigned char receiveBuffer[256];
	
	void sendMessage();
	void receiveMessage(const boost::system::error_code &ec, std::size_t bytes_transferred);
};
#endif