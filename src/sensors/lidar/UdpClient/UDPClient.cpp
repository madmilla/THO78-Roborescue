#include "UDPClient.h"

#define CPI_IP_ADRESS "172.16.120.129"
#define PORT 8888
#define LONG_SLEEP 1
#define SHORT_SLEEP 500


UDPClient::UDPClient(): stopped{false}, lidar{nullptr}{
	sockbind();

	connectionThread = new std::thread(&UDPClient::start, this);
	connectionThread->detach();
}

UDPClient::~UDPClient(){
	stop();
	delete connectionThread;
}

void UDPClient::sockbind(){
	remoteadr = SocketAddress{CPI_IP_ADRESS, PORT, SocketAddress::UDP_SOCKET};
}

void UDPClient::start(){
	while(true){
		std::cout << "Client" << std::endl;
		checkConnectionStatus();
		receive();
		std::queue<mavlink_message_t> * messages = lidar->getMessageQueue();
		while(!messages->empty()){
			send(messages->front());
			usleep(SHORT_SLEEP);
			messages->pop();
		}
		sleep(LONG_SLEEP);
	}
}

int UDPClient::send(mavlink_message_t message){
	try{
		sock.sendTo(&message, sizeof(mavlink_message_t), remoteadr );
	}catch(SocketException e){
		sockbind();
		std::cout << "Bericht kan niet verzonden worden: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

void UDPClient::receive(){
	try{
		mavlink_message_t msg{0,0,0,0,0,0,0,0};
		sock.recvFrom(&msg, sizeof(mavlink_message_t), remoteadr);

		if(msg.len != 0 && msg.payload64 != 0){
			lidar->onMessage(msg);
		}

	}catch(SocketException e){
		sockbind();
		std::cout << "Bericht kan niet verzonden worden: " << e.what() << std::endl;
	}
}

void UDPClient::stop(){
	stopped = true;
	sock.close();
}

void UDPClient::checkConnectionStatus(){
	while(send(mavlink_message_t{0,0,0,0,0,0,0,0}) != 0){
		std::cout << "Kan geen verbinding maken met CPI" << std::endl;;
		sleep(LONG_SLEEP);
	}
}
