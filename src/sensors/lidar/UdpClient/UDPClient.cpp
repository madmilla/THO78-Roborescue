#include "UDPClient.h"

#define ipAddress "192.168.43.121"
#define port 8080


UDPClient::UDPClient(): Socketlistener{nullptr}{
	sockbind();

	mavlink_ralcp_t ralcp{0, 0, 0};
	sock.sendTo(&ralcp, sizeof(mavlink_ralcp_t), remoteadr );

	connectionThread = new std::thread(&UDPClient::start, this);
	connectionThread->detach();
}

UDPClient::~UDPClient(){
	stop();
	delete connectionThread;
}

void UDPClient::sockbind(){
	remoteadr = SocketAddress{ipAddress, port, SocketAddress::UDP_SOCKET};
}

void UDPClient::start(){
	while(true){
		receive();
		std::queue<mavlink_ralcp_t> * messages = Socketlistener->getMessageQueue();
		while(!messages->empty()){
			send(messages->front());
			sleep(1);
			messages->pop();
		}
		sleep(1);
	}
}

void UDPClient::send(mavlink_ralcp_t message){
	sock.sendTo(&message, sizeof(mavlink_ralcp_t), remoteadr);
}

void UDPClient::receive(){
	mavlink_ralcp_t ralcp{0,0,0};
	sock.recvFrom(&ralcp, sizeof(mavlink_ralcp_t), remoteadr);
	Socketlistener->onMessage(ralcp);
}

void UDPClient::stop(){
	stopped = true;
}
