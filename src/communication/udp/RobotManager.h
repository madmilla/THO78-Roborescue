#ifndef __ROBOTMANAGER__
#define __ROBOTMANAGER__
#include <vector>
#include "Rosbee.hpp"

class RobotManager{
public:
	static RobotManager * get();

	Rosbee * createRosbee(Socket s);

private:
	RobotManager(){}
	std::vector<CPIBoundaryObject * > robots;
	static RobotManager * instance;



};
#endif