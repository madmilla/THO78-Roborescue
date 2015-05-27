#ifndef __ROBOTMANAGER__
#define __ROBOTMANAGER__
#include <vector>
#include <exception>
#include <sstream>
#include "Rosbee.hpp"
#include "Lidar.h"

class UDPSocket;
class Rosbee;
class RobotManager{
public:
	RobotManager(){}

	Rosbee * createRosbee(UDPSocket * s);
	
	template<typename T>
	std::vector<T *> getRobots();
	
	template<typename T>
	T * getRosbee(int id);
	
	std::string getDetails();

	Lidar * createLidar(UDPSocket * s);
	std::vector<Lidar *> getLidar();
	Lidar * getLidar(int id);
	std::string getDetails();

	int size();
private:
	std::vector<CPIBoundaryObject * > robots;

};
#endif