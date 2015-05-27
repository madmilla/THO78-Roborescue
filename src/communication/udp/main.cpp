#include "UDPServer.hpp"
int main(){
	RobotManager manager;
	
	UDPServer udp(manager);
	int cons = 0;
	while(true){
		if(manager.size() > cons){
			std::cout << manager.getDetails();
			auto rosbee = manager.getRosbee(cons);
			rosbee->init();
			cons++;
			}
	}

	exit(0);
}