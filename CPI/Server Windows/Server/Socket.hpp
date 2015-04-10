#ifndef __SOCKET__
#define __SOCKET__
#include <queue>
#include "../../mavlink_commands/mavlink_commands/mavlink.h"
class UDPServer;

class Socket
{
public:
	Socket(){}
	virtual void send(mavlink_message_t * message) {}
	virtual void receive(mavlink_message_t * message){}
	virtual uint8_t getId(){ return 0; }
	~Socket(){}
private:
	std::queue<mavlink_message_t *> commandQueue;


};
#endif