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

template <typename T>
std::vector<T *> RobotManager::getRobots(){
	std::vector<T *> list;
	for(auto robot : robots){
		auto r = static_cast<T *>(robot);
		if(r != nullptr){
			list.push_back(r);
		}

	}
	return list;
}

template <typename T>
T * RobotManager::getRobot(int id){
	for(auto robot: robots){
		auto r = static_cast<T *>(robot);
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
	for(auto rosbee : getRobots<Rosbee>()){
		ss << "\tId: " << rosbee->getId() << std::endl;

	}
	ss << std::endl;

	return ss.str();

}
