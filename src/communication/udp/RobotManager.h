#ifndef __ROBOTMANAGER__
#define __ROBOTMANAGER__
#include <vector>
#include <exception>
#include <sstream>
#include "Rosbee.hpp"
#include "Lidar.h"

class UDPSocket;
class Rosbee;
class Lidar;
class RobotManager{
public:
	RobotManager(){}

	void createUDPRobot(UDPSocket * s);

	
	template<typename T>
	T * getRobot(int id){
		for(auto robot: robots){
			auto r = dynamic_cast<T *>(robot);
			if(r != nullptr){
				if(id == r->getId()){
					return r;
				}
			}
		}
		return nullptr;
	}
	
template <typename T>
std::vector<T *> getRobots(){
	std::vector<T *> list;

	for(auto robot : robots){
		auto r = dynamic_cast<T *>(robot);
		if(r != nullptr){
			list.push_back(r);
		}

	}
	return list;
}
	
	template <typename T>
	T * createRobot(UDPSocket * s){
		T * robot= new T(s);
		robots.push_back(robot);
		return robot;
	}

	std::string getDetails();

	int size();
private:
	std::vector<CPIBoundaryObject * > robots;

};
#endif