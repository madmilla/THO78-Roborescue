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
	const vector<Line> &  m = map.getMapTotal();
	return createPathToDestination(m, point(x1,y1), point(x2,y2));
}

const vector<point> & Surroundings::updatemap(Vector<Line> & map, int x, int y){
	const auto & x;
	for(const Line & l : map){
		map.setLine(l.x1,l.y1,l.x2.l.y2);
		x = sendMapLine(l, point(x,y))
	}
	return x;
}

const vector<line> & Surroundings::getMap(){
	return map.getMapTotal();
}

//TODO: make this work
const vector<point> & Surroundings::getPath(int deviceType,int deviceId){
	
}

//TODO: make this work
const point & Surroundings::getPosition(int deviceType,int deviceId){
	
}

void recieveVisionData(auto visionData){
	strategy.recieveVisionData(visionData);
}

void sendRosbeeData(auto gyroscopeData){
	strategy.sendRosbeeData(gyroscopeData);
}