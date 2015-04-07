#include "Surroundings.hpp"

Surroundings::Surroundings(): 
map(CommandsMap.getInstance()),
strategy(CommandsStrategy.getInstance()){
	
}

Surroundings::Surroundings(Map & m, Strategy & s) 
map(m),
strategy(s){
	
}

bool Surroundings::setLocation(int x,int y,int deviceType, int deviceId){
	return map.setLocation(x,y,deviceType,deviceId);
}

bool Surroundings::moveLocation(int x,int y,int deviceType, int deviceId){
	point p = map.getLocation(int deviceType,int deviceId)
	return map.setLocation(p.x + x,p.y + y,deviceType,deviceId);
}

const vector<point> & Surroundings::getCompletePath(int x1,int y1, int x2,int y2){
}

const vector<point> & Surroundings::updatemap(Vector<point> & map, int x, int y){
	
}

const vector<line> & Surroundings::getMap(){
	return map.getMapTotal();
}

const vector<point> & Surroundings::getPath(int deviceType,int deviceId){
	
}

const point & Surroundings::getPosition(int deviceType,int deviceId){
	
}

	void recieveVisionData(auto visionData);

	//!  \brief sends rosbee gyroscoop data to strategy.
	//! \param[in] gyroscopeData contains the rosbee gyroscope data for the strategy
	void sendRosbeeData(auto gyroscopeData);