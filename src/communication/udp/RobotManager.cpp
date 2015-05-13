#include "RobotManager.h"
RobotManager * RobotManager::instance = nullptr;

RobotManager * RobotManager::get(){
	if(!instance){
		instance = new RobotManager;
	}
	return instance;
}

Rosbee * RobotManager::createRosbee(Socket s){
	Rosbee * rosbee = new Rosbee(s);
	robots.push_back(rosbee);
	return rosbee;

}

