#include "UDPSocket.hpp"
void UDPSocket::send(mavlink_message_t * message){
   server->send(*this, message);
}

	void UDPSocket::receive(mavlink_message_t * message){
		incomming->add(message);
	}