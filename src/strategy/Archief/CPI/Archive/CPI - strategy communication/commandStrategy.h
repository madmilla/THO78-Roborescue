//! \file Surroundings.hpp
//! \class Surroundings
//! \brief A class that combines the functionality of both the Mapping and 
//! the strategy
//! \details A class that combines the functionality of both the Mapping and 
//! the strategy
//! This class sends data about mapping and pathfinding from and to the
//! correct classes
//! There should not be any direct communication to the map and strategy.
//! \author    Tom Verloop & Thijs van Tiem
//! \version   1.0
//! \date      7-4-2015
//! \warning  


#ifndef COMMANDSTRATEGY_H_
#define COMMANDSTRATEGY_H_

namespace CommandStrategy {

#include <iostream>
#include <vector>

class CommandStrategy {
public:
   
   //! singleton class
   CommandStrategy & getInstance();
   
   virtual ~CommandStrategy();
   
   //! function that will send received map data from the map (entire map) 
   //! to the strategy team as a
   //! vector with x and y axes. (in the further degree’s might be added).
   //! return value is the route (lots of x and y point in vectors where
   //! we will navigate on)
   const std::vector<point> & createPathToDestination(
                                 vector<Line> & map, 
                                 const point & position, 
                                 const point & destination,
                                 int deviceId
                              );
   
   //! function that creates a path sees the entire room
   //! based on the sight range of the vechicle
   //! retruns a route composed of waypoints
   const std::vector<point> & createAreaCoveragePath(
                                 vector<line> & map,
                                 const point & position, 
                                 Dimension sightRange
                              );
   
   //! function that sends the lines received from the map to the strategy team
   //! (Not sure if this function will be used but might be usefull in the 
   //! further)
   const std::vector<point> & sendMapLine(Line & l, const point & position)
   
   //! they need this to navigate the rosbee and will use the direction data
   //!   of the compass
   //! It is not certain that this function will be used.
   void recieveRosbeeData(auto directionData);
   
   //! Give directions to the rosbee where to drive
   //! Afterwards the robsee will send his data to mapping and we will decide
   //!   where it will move next
   void sendRosbeeDirections(waypoint waypoint);
   
   
   //! processed vision data the will be used in the next sprint.
   //! parameters are auto for the moment. Do not know how to do this yet 
   //!(next sprint)
   void recieveVisionData(auto visionData);
   
   //! function not sure yet.
   void sendRosbeeData(auto gyroscopeData);
   
   
private:
   CommandStrategy();
};

} /* namespace commandStrategy */

#endif /* COMMANDSTRATEGY_H_ */
