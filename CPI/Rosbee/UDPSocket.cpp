#include "UDPSocket.hpp"
void UDPSocket::send(MavLinkMessage_t * message){
		server.send(con, message);
	}
	void UDPSocket::receive(MavLinkMessage_t * message){
		server.receive(message);
	}
