#ifndef __UDPSOCKET__
#define __UDPSOCKET__
#include "Connection.hpp"
#include "Socket.hpp"
#include "UDPServer.hpp"
#include "..\mavlink_commands\mavlink_commands\mavlink.h"

class UDPSocket : Socket
{
public:
	UDPSocket(Connection c, UDPServer & serv) : con(c), server(serv){}
	void send(mavlink_message_t * message) override;
	void receive(mavlink_message_t * message) override;
	~UDPSocket();
private:
	friend class UDPServer;
	Connection con;
	std::vector<mavlink_message_t> responses;
	UDPServer & server;
};
#endif