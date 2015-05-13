#ifndef __ROBOTMANAGER__
#define __ROBOTMANAGER__
#include <vector>
#include <exception>
#include "Rosbee.hpp"
class Rosbee;
class RobotManager{
public:
	static RobotManager * get();

	Rosbee * createRosbee(Socket & s);

private:
	RobotManager(){}
	std::vector<CPIBoundaryObject * > robots;
	static RobotManager * instance;
	//! \brief Copy constructor this shouldn't be implemented
	RobotManager(RobotManager const&){};	

	//! \brief =opperator this shouldn't be implemented for singleton's sake
	RobotManager& operator=(RobotManager const &){};


};
#endif