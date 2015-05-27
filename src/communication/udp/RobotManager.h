#ifndef __ROBOTMANAGER__
#define __ROBOTMANAGER__
#include <vector>
#include <exception>
#include <sstream>
#include "Rosbee.hpp"
class UDPSocket;
class Rosbee;
class RobotManager{
public:
	RobotManager(){}
	Rosbee * createRosbee(UDPSocket * s);
	std::vector<Rosbee *> getRosbee();
	Rosbee * getRosbee(int id);
	std::string getDetails();
	int size();
private:
	std::vector<CPIBoundaryObject * > robots;

};
#endif