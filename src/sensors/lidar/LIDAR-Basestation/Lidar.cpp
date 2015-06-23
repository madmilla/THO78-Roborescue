#include "Lidar.h"

Lidar::Lidar(CPIUDPSocket * s) : sock(s){

	encoder = new RALCPEncoder(s, s->getId(), 0, 0, 0);
	outgoing = new MessageQueue<std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>>();
	start();
}

void Lidar::run(){

	running = true;
	while (running){

		if (outgoing->size() > 0){
			auto pair = outgoing->pop();
			encoder->send(COMMAND_DESTINATION::LIDAR, pair.first, pair.second);
			std::cout << "Send message!" << std::endl;
		}
		if (sock->incomming->size() > 0){
			//Do stuff with incomming messages
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

}

void Lidar::init(){
	message[0] = 0;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT, message));
}

void Lidar::recieveLine(){
	message[0] = 0;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::LINEDATA, message));
}

void Lidar::recieveRpm(){
	message[0] = 0;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::RPM, message));
}

void Lidar::Start(){
	message[0] = 0;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::START, message));
}

void Lidar::Stop(){
	message[0] = 0;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::STOP, message));
}

void Lidar::sendRosbeePositie(int x, int y){
	message[0] = x;
	message[1] = y;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION, message));
}

void Lidar::sendRosbeeFlank(int degrees){
	message[0] = degrees;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK, message));
}

void Lidar::getDevice(uint8_t dev){
	message[0] = dev;
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint32_t[5]>(LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE, message));
}

int Lidar::getId(){
	return sock->getId();
}

void Lidar::abort(){
	running = false;
}
