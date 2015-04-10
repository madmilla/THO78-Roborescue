#ifndef __CONNECTION__
#define __CONNECTION__

#include <winsock2.h>
#include "UDPServer.hpp"
class UDPServer;
struct Connection{
public:
	
	enum Identifier{
		UNKNOWN,
		ROSBEE,
		LIDAR,
		QUADCOPTER,
		ATV
	};

	Connection(uint8_t ids, Connection::Identifier i, sockaddr_in sock) : id(ids), type(i), sockaddr(sock){}

	Identifier type;
	uint8_t id;
	sockaddr_in sockaddr;
}; 

#endif // !__CONNECTION__
