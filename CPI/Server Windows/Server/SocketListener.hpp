#include "UDPServer.hpp"
#include "Connection.hpp"
class SocketListener
{
public:
	void received(Connection::Identifier id, char * data){
	}

	SocketListener();
	~SocketListener();
};