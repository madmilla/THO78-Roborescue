#include "RobotManager.h"

Rosbee * RobotManager::createRosbee(UDPSocket * s){
	try{
		Rosbee * rosbee = new Rosbee(s);
		robots.push_back(rosbee);
		return rosbee;
	}catch(std::exception &ex){
		std::cout << ex.what();
	}
}

std::vector<Rosbee *> RobotManager::getRosbee(){
	std::vector<Rosbee *> list;
	for(auto robot : robots){
		auto r = static_cast<Rosbee *>(robot);
		if(r != nullptr){
			list.push_back(r);
		}

	}
	return list;
}

Rosbee * RobotManager::getRosbee(int id){
	for(auto robot: robots){
		auto r = static_cast<Rosbee *>(robot);
		if(r != nullptr){
			if(id == r->getId()){
				return r;
			}
		}
	}
	return nullptr;
}

Lidar * RobotManager::createLidar(UDPSocket * s){
	try{
		Lidar * rosbee = new Lidar(s);
		robots.push_back(rosbee);
		return rosbee;
	}
	catch (std::exception &ex){
		std::cout << ex.what();
	}
}

std::vector<Lidar *> RobotManager::getLidar(){
	std::vector<Lidar *> list;
	for (auto robot : robots){
		auto r = static_cast<Lidar *>(robot);
		if (r != nullptr){
			list.push_back(r);
		}

	}
	return list;
}

Lidar * RobotManager::getLidar(int id){
	for (auto robot : robots){
		auto r = static_cast<Lidar *>(robot);
		if (r != nullptr){
			if (id == r->getId()){
				return r;
			}
		}
	}
	return nullptr;
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
	for(auto rosbee : getRosbee()){
		ss << "\tId: " << rosbee->getId() << std::endl;

	}
	ss << std::endl;

	return ss.str();

}
