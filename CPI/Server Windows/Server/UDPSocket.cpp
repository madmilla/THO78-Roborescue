#include "UDPSocket.hpp"
void UDPSocket::send(mavlink_message_t * message){
		server.send(con, message);
	}
	void UDPSocket::receive(mavlink_message_t * message){
		server.receive(message);
	}
