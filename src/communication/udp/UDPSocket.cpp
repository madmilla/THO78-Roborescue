#include "UDPSocket.hpp"
void UDPSocket::send(mavlink_message_t * message){
   server->send(this, message);
}

	void UDPSocket::receive(mavlink_message_t * message){
		incomming->add(message);
	}

void UDPSocket::print(){
	std::cout << "Id: "<< con.id << std::endl;
	std::cout << "IP: " << inet_ntoa(con.sockaddr.sin_addr) << ":" << con.sockaddr.sin_port << std::endl;
}