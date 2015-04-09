#ifndef _SURROUNDINGS_H_
#define _SURROUNDINGS_H_

#include "commandsMap.h"
#include "commandsStrategy.hpp"

//! \file Surroundings.hpp
//! \class Surroundings
//! \brief A class that combines the functionality of both the Mapping and the strategy
//! \details A class that combines the functionality of both the Mapping and the strategy
//! This class sends data about mapping and pathfinding from and to the correct classes
//! There should not be any direct communication to the map and strategy.
//! \author    Tom Verloop
//! \version   1.0
//! \date      7-4-2015
//! \warning   

class Surroundings
{

public:
	
	//! \brief standard constructor
	Surroundings();
	
	//! \brief standard constructor
	//! \param[in] m a reference to the CommandsMap class
	//! \param[in] s a reference to the CommandsStrategy class
	Surroundings(CommandsMap & m, CommandsStrategy & s);
	
	
	//! \brief sets the location of the robot
	//! \param[in] p  coordinate of the robot
	//! \param[in] deviceType this tells which kind of robot it is
	//! \param[in] deviceId the ID of the robot
	//! \return returns true if moving the marker succeeded
	bool setLocation(const Point & p,RobotType deviceType, int deviceId);
	
	//! \brief instead of setting the position it moves it by 
	//! adding x and y to the current position
	//! \param[in] p  coordinate of the robot
	//! \param[in] deviceType this tells which kind of robot it is
	//! \param[in] deviceId the ID of the robot
	//! \return returns true if moving the marker succeeded
	bool moveLocation(const Point & p,RobotType deviceType, int deviceId);
	
	//! \brief calculates the path from start to finish.
	//! \param[in] start the coordinate of the start location
	//! \param[in] finish the coordinate of the destination
	//! \return returns the path as a vector of waypoints
	const vector<point> & getCompletePath(const Point & start, const Point & finish);
	
	//! \brief calculates the path from start to finish.
	//! \param[in] p the coordinate of the start location
	//! \param[in] map contains a vector of points which represents the map
	//! \return gets the new waypoints for the rosbee
	const vector<point> & updatemap(Vector<Line> & map,const Point & p);
	
	//! \brief returns the whole map as a vector of lines
	//! \return gets the new waypoints for the rosbee
	const vector<Line> & getMap();
	
	//! \brief returns the position of a given robot as a waypoint
	//! \param[in] deviceType this tells which kind of robot it is
	//! \param[in] deviceId the ID of the robot
	//! \return returns a position in way of a waypoint
	const point & getPosition(RobotType deviceType,int deviceId);
	
	//! \brief processed vision data the will be used in the next sprint.
	//! parameters are auto for the moment. Do not know how to do this yet (next sprint)
	//! \param[in] visionData contains an image for the strategy
	void recieveVisionData(auto visionData);

	//! \brief sends rosbee gyroscoop data to strategy.
	//! \param[in] gyroscopeData contains the rosbee gyroscope data for the strategy
	void sendRosbeeData(auto gyroscopeData);
	
private:
	//! a reference to the CommandsMap class
	CommandsMap map;
	//! a reference to the CommandsStrategy class
	CommandsStrategy strategy;
	
	
}

class enum RobotType
{
	Quad = 1,
	ATV = 2,
	Rosbee = 3;
}

#endif //! _SURROUNDINGS_H_