#ifndef __CONNECTION__
#define __CONNECTION__

#include<winsock2.h>
#include "UDPServer.hpp"
struct Connection{
public:
	enum Identifier{
		ROSBEE,
		LIDAR,
		QUADCOPTER,
		ATV
	};

	Connection(Identifier i, sockaddr_in sock){
		id = UDPServer::currentid++;
	}

	Identifier type;
	uint8_t id;
	sockaddr_in sockaddr;
}; 
#endif // !__CONNECTION__
