#ifndef __CONNECTION__
#define __CONNECTION__

#include <winsock2.h>
#include "UDPServer.hpp"

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \struct Connection
/// \brief This is helper struct containing infromation of the connection, like what device is connected and on what socket this connection also carries a unique id for identification
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
