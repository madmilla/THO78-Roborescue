#ifndef __SOCKET__
#define __SOCKET__
#include "Connection.hpp"
#include <queue>
#include "UDPServer.hpp"
#include "..\mavlink_commands\protocol.h"
class Socket
{
public:
	Socket();
	virtual void send(mavlink_message_t * message) ;
	virtual void receive(mavlink_message_t * message);
	~Socket();
protected:
	UDPServer server;
private:
	std::queue<mavlink_message_t *> commandQueue;


};
#endif