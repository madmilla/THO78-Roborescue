//!  commands mapping team
//!  Made by ThijsvanTiem
/*!
    header file for commands between the CC and the strategy team
*/
#ifndef COMMANDSTRATEGY_H_
#define COMMANDSTRATEGY_H_


#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#elif __linux__
#define DLLEXPORT
#else
#define DLLEXPORT
#endif

namespace commandStrategy {

#include <iostream>
#include <vector>

class DLLEXPORT commandStrategy {
public:

	//! singleton class
	commandStrategy() & getInstance();
	
	virtual ~commandStrategy();
	
	//! function that will send received map data from the map (entire map) to the strategy team as a
	//! vector with x and y axes. (in the further degree’s might be added).
	//! return value is the route (lots of x and y point in vectors where we will navigate on)
	std::vector<int> sendMapData(vector<Line> & map);

	//! function that sends the lines received from the map to the strategy team
	//! (Not sure if this function will be used but might be usefull in the further)
	std::vector<int >sendMapLine(Line & l)

	//! processed vision data the will be used in the next sprint.
	//! parameters are auto for the moment. Do not know how to do this yet (next sprint)
	void recieveVisionData(auto visionData);


	//! function not sure yet.
	void sendRosbeeData(auto gyroscopeData);


private:
	commandStrategy();
};

} /* namespace commandStrategy */

#endif /* COMMANDSTRATEGY_H_ */
