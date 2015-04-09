#include "Connection.hpp"
#include <queue>
class Socket
{
public:
	Socket();
	virtual void send(MavLinkMessage_t * message) = 0;
	virtual void receive(MavLinkMessage_t * message) = 0;
	~Socket();
private:
	std::queue<MavLinkMessage_t> commandQueue;

};