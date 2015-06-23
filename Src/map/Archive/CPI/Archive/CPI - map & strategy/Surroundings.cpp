#include "Surroundings.hpp"

Surroundings::Surroundings(): 
map(CommandsMap.getInstance()),
strategy(CommandsStrategy.getInstance()){

}

Surroundings::Surroundings(CommandsMap & map, CommandsStrategy & strategy)
map(m),
strategy(s){

}

bool Surroundings::setLocation(
                      const Point & position,
                      RobotType deviceType, 
                      int deviceId
                   ){
   return map.setLocation(p.getX(),p.getY(),deviceType,deviceId);
}

bool Surroundings::moveLocation(
                      const Point & position,
                      RobotType deviceType, 
                      int deviceId
                   ){
   point p2 = map.getLocation(int deviceType,int deviceId)
   return map.setLocation(
                 p2.getX() + p.getX(),
                 p2.getY() + p.getY(),
                 deviceType,deviceId
              );
}

const vector<point> & Surroundings::getCompletePath(
                         const Point & start, 
                         const Point & finish
                      ){
   const vector<Line> &  m = map.getMapTotal();
   return createPathToDestination(m, start,finish,deviceId);
}

const vector<point> & Surroundings::updatemap(
                                       Vector<Line> & map,
                                       const Point & position)
                                    {
   const auto & x;
   for(const Line & l : map){
      map.setLine(
             l.getPoint(0).getX(),
             l.getPoint(0).getY(),
             l.getPoint(1).getX(),
             l.getPoint(1).getY()
          );
      x = sendMapLine(l, p);
   }
   return x;
}

const vector<line> & Surroundings::getMap(){
   return map.getMapTotal();
}

//TODO: make this work
const point & Surroundings::getPosition(RobotType deviceType,int deviceId){
   return map.getPosition(deviceType,deviceId);
}

void recieveVisionData(auto visionData){
   strategy.recieveVisionData(visionData);
}

void sendRosbeeData(auto gyroscopeData){
   strategy.sendRosbeeData(gyroscopeData);
}