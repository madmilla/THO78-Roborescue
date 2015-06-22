#include "Lidar.h"

Lidar::Lidar(CPIUDPSocket * s) : sock(s){

	encoder = new RALCPEncoder(s, s->getId(), 0, 0, 0);
	outgoing = new MessageQueue<std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>>();
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
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT, 0));
}

void Lidar::recieveLine(){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::LINEDATA, 0));
}

void Lidar::recieveRpm(){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::RPM, 0));
}

void Lidar::Start(){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::START, 0));
}

void Lidar::Stop(){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::STOP, 0));
}

void Lidar::sendRosbeePositie(int postion){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION, postion));
}

void Lidar::sendRosbeeFlank(int degrees){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK, degrees));
}

void Lidar::getDevice(uint8_t dev){
	outgoing->add(std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>(LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE, uint64_t(dev << 54)));
}

int Lidar::getId(){
	return sock->getId();
}

void Lidar::abort(){
	running = false;
}