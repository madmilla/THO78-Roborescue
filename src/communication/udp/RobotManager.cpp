#include "RobotManager.h"


void RobotManager::createUDPRobot(CPIUDPSocket * s){
	if((s = static_cast<CPIUDPSocket*>(s)) != nullptr ){
		switch(s->con.type){
			case Connection::Identifier::ROSBEE:
				createRobot<Rosbee>(s);
			break;
			case Connection::Identifier::LIDAR:
				createRobot<Lidar>(s);
			break;
			default:
				std::cout << "Unkown destination";
			break;
		}
	}else{


	}
}




int RobotManager::size(){
	return robots.size();
}

std::string RobotManager::getDetails(){
	std::stringstream ss;
	ss << "=============================" << std::endl;
	ss << "=        RobotManager       =" << std::endl;
	ss << "=============================" << std::endl;
	ss << std::endl;
	ss << "General Information: "<<std::endl;
	ss << "\tConnected robots: " << robots.size() << std::endl;
	ss << std::endl;
	ss << "Rosbee's:"<<std::endl;
	for(auto rosbee : getRobots<Rosbee>()){
		ss << "\tId: " << rosbee->getId() << std::endl;
	}
	ss << "Lidar's" << std::endl;
	for(auto lidar : getRobots<Lidar>()){
		ss << "\tId: " << lidar->getId() << std::endl;
	}
	ss << std::endl;

	return ss.str();

}
