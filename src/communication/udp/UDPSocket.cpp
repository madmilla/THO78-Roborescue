#include "UDPSocket.h"
void CPIUDPSocket::send(mavlink_message_t * message){

   server->send(this, message);
}

	void CPIUDPSocket::receive(mavlink_message_t * message){
		incomming->add(message);
	}

void CPIUDPSocket::print(){
	std::cout << "Id: "<< con.id << std::endl;
	std::cout << "IP: " <<con.sockaddr << ":" << con.port << std::endl;
}