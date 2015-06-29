#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "roborescueV1/mavlink.h"
#include <boost/asio.hpp>

class TCPConnection;

class MAVLinkExchanger
{
public:
	explicit MAVLinkExchanger(TCPConnection& dataPort);
	void enqueueMessage(mavlink_message_t& message);
	mavlink_message_t dequeueMessage();
	mavlink_message_t peek();
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