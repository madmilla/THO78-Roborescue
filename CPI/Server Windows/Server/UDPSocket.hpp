#ifndef __UDPSOCKET__
#define __UDPSOCKET__
#include "Socket.hpp"
#include "Connection.hpp"
#include "UDPServer.hpp"
#include "..\..\mavlink_commands\mavlink_commands\mavlink.h"

class UDPSocket : public Socket
{
public:
	UDPSocket(Connection c, UDPServer * serv) : con(c), server(serv){}
	void send(mavlink_message_t * message) override;
	void receive(mavlink_message_t * message) override;
	uint8_t getId() override { return con.id; }
	~UDPSocket(){}
private:
	friend class UDPServer;
	UDPServer * server;
	Connection con;
	std::vector<mavlink_message_t> responses;
};
#endif