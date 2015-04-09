#include "SurroundingsUnitTest.h"

constexpr int maxDeviceType = 1;
constexpr int maxDeviceId = 1;
constexpr Point maxPoint = Point(100,100);
constexpr Point AvailableStartInMap = Point(0,0);
constexpr Point AvailableEndInMap = Point(0,0);
constexpr Point UnAvailableStartInMap = Point(100,0);
constexpr Point UnAvailableEndInMap = Point(0,100);
main()
{
	Surroundings s;
	
	
	//Tests for bool setLocation(const Point & p,RobotType deviceType, int deviceId);
	if(s.setLocation(NULL,1,1))
	{
		return 1;
	}
	if(s.setLocation(Point(0,0),-1,1))
	{
		return 2;
	}
	if(s.setLocation(Point(0,0),1,-1))
	{
		return 3;
	}
	if(s.setLocation(maxPoint + Point(1,1),1,1))
	{
		return 4;
	}
	if(s.setLocation(Point(0,0),maxDeviceType+1,1))
	{
		return 5;
	}
	if(s.setLocation(Point(0,0),1,maxDeviceId+1))
	{
		return 6;
	}
	if(!s.setLocation(Point(0,0),1,1))
	{
		return 7;
	}setLocation(maxPoint,1,1)
	{
		return 8;
	}
	if(!s.setLocation(Point(0,0),maxDeviceType,1))
	{
		return 9;
	}
	if(!s.setLocation(Point(0,0),1,maxDeviceId))
	{
		return 10;
	}
	
	point p(0,0);
	if(s..setLocation(p,1,1))
	{
		if(p != s.getPosition(1,1)){
			return 12;
		}
	}else{
		return 11;
	}
	
	if(s.setLocation(maxPoint,1,1))
	{
		if(maxPoint != s.getPosition(1,1)){
			return 14;
		}
	}else{
		return 13;
	}
	
	
	//Tests for const vector<point> & getCompletePath(const Point & start, const Point & finish);
	if(s.getCompletePath(NULL,NULL) != NULL){
		return 15;
	}
	if(s.getCompletePath(Point(0,0),NULL) != NULL){
		return 16;
	}
	if(s.getCompletePath(NULL,Point(0,0)) != NULL){
		return 17;
	}
	if(s.getCompletePath(NULL,Point(0,0)) != NULL){
		return 18;
	}
	if(s.getCompletePath(NULL,Point(0,0)) != NULL){
		return 19;
	}
	if(s.getCompletePath(UnAvailableStartInMap,UnAvailableEndInMap) != NULL){
		return 20;
	}
	if(s.getCompletePath(AvailableStartInMap,UnAvailableEndInMap) != NULL){
		return 21;
	}
	if(s.getCompletePath(UnAvailableStartInMap,AvailableEndInMap) != NULL){
		return 22;
	}
	if(!s.getCompletePath(AvailableStartInMap,AvailableEndInMap) != NULL){
		return 23;
	}
	
	
	
}