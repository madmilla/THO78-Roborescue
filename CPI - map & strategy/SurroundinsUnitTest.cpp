#include "SurroundingsUnitTest.h"

constexpr int maxDeviceType = 1;
constexpr int maxDeviceId = 1;
constexpr Point maxPoint = Point(100,100);
constexpr Point AvailableStartInMap = Point(0,0);
constexpr Point AvailableEndInMap = Point(0,0);
constexpr Point UnAvailableStartInMap = Point(100,0);
constexpr Point UnAvailableEndInMap = Point(0,100);
constexpr Point RosbeeValidTestPoint = Point(50,50);
constexpr Point RosbeeINValidTestPoint = Point(50,50);
constexpr Map TestMap = Map();

main()
{
	Surroundings s;
	
	
	//Tests for bool setLocation(const Point & p,RobotType deviceType, int deviceId);
	
	//Test if nullptr is accepted for point
	if(s.setLocation(nullptr,1,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : nullptr as Point got accepted";
		return 1;
	}
	
	//Test if values below 0 are accepted as robottype
	if(s.setLocation(Point(0,0),-1,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : -1 as robottype got accepted";
		return 2;
	}
	
	//Test if values below 0 are accepted as robotid
	if(s.setLocation(Point(0,0),1,-1))
	{
		return 3;
	}
	
	//Test if a point beyond its max value is accepted
	if(s.setLocation(maxPoint + Point(1,1),1,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : overflow in Point got accepted";
		return 4;
	}
	
	//Test if a DeviceType beyond its max value is accepted
	if(s.setLocation(Point(0,0),maxDeviceType+1,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : overflow in Robottype got accepted";
		return 5;
	}
	
	//Test if a DeviceID beyond its max value is accepted
	if(s.setLocation(Point(0,0),1,maxDeviceId+1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : overflow in Id got accepted";
		return 6;
	}
	
	//Test if a Minimum valid point value is accepted
	if(!s.setLocation(Point(0,0),1,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : Valid min point input did not get accepted";
		return 7;
	}
	
	//Test if a Maxmimum valid point value is accepted
	if(!s.setLocation(maxPoint,1,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : Valid max point input did not get accepted";
		return 8;
	}
	
	//Test if a Maxmimum valid devicetype value is accepted
	if(!s.setLocation(Point(0,0),maxDeviceType,1))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : Valid max DeviceType input did not get accepted";
		return 9;
	}
	
	//Test if a Maxmimum valid deviceid value is accepted
	if(!s.setLocation(Point(0,0),1,maxDeviceId))
	{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : Valid max DeviceId input did not get accepted";
		return 10;
	}
	
	
	//Test if a minimum valid location is correctly remembered
	point p(0,0);
	if(s.setLocation(p,1,1))
	{
		if(p != s.getPosition(1,1)){
			std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : New Min position is not the same as set position";
			return 12;
		}
	}else{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : Valid SetLocation did not get accepted";
		return 11;
	}
	
	
	//Test if a maximum valid location is correctly remembered
	if(s.setLocation(maxPoint,1,1))
	{
		if(maxPoint != s.getPosition(1,1)){
			std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : New Max position is not the same as set position";
			return 14;
		}
	}else{
		std::cerr << "bool setLocation(const Point & p,RobotType deviceType, int deviceId) : Valid SetLocation did not get accepted";
		return 13;
	}
	
	
	//Tests for const vector<point> & getCompletePath(const Point & start, const Point & finish);
	
	
	
	//Test if a path is genereted with nullptr any parameters is accepted
	if(s.getCompletePath(nullptr,nullptr) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : Empty parameters got accepted";
		return 15;
	}
	
	//Test if a path is genereted with nullptr as finish point is accepted
	if(s.getCompletePath(Point(0,0),nullptr) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : nullptr endpoint got accepted";
		return 16;
	}
	
	//Test if a path is genereted with nullptr as start point is accepted
	if(s.getCompletePath(nullptr,Point(0,0)) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : nullptr startpoint got accepted";
		return 17;
	}
	
	//Test if a path is genereted with a invalid start and end is accepted
	if(s.getCompletePath(UnAvailableStartInMap,UnAvailableEndInMap) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : Inpropriate parameters got accepted";
		return 18;
	}
	
	//Test if a path is genereted with a invalid end is accepted
	if(s.getCompletePath(AvailableStartInMap,UnAvailableEndInMap) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : Inpropriate Endpoint got accepted";
		return 19;
	}
	
	//Test if a path is genereted with a invalid start is accepted
	if(s.getCompletePath(UnAvailableStartInMap,AvailableEndInMap) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : Inpropriate Beginpoint got accepted";
		return 20;
	}
	
	//Test if a path is genereted with a valid start and end is accepted
	if(!s.getCompletePath(AvailableStartInMap,AvailableEndInMap) != nullptr){
		std::cerr << "const vector<point> & getCompletePath(const Point & start, const Point & finish) : Appropriate parameters did not get accepted";
		return 21;
	}
	
	
	//Tests for const vector<point> & updatemap(Vector<Line> & map,const Point & p);
	
	
	//Test if a mapupdate with a nullptr as maplines is accepted
	if(s.updatemap(nullptr,RosbeeValidTestPoint) != nullptr){
		std::cerr << "const vector<point> & updatemap(Vector<Line> & map,const Point & p) : nullptr as map got accepted";
		return 22;
	}
	
	//Test if a mapupdate with a nullptr as position is accepted
	if(s.updatemap(TestMap,nullptr) != nullptr){
		std::cerr << "const vector<point> & updatemap(Vector<Line> & map,const Point & p) : nullptr as location got accepted";
		return 23;
	}
	
	//Test if a mapupdate with a nullptr as both parameters
	if(s.updatemap(nullptr,nullptr) != nullptrptr){
		std::cerr << "const vector<point> & updatemap(Vector<Line> & map,const Point & p) : nullptr as both parameters got accepted";
		return 24;
	}
	
	//Test if a mapupdate with a invalid position is accepted
	if(s.updatemap(TestMap,RosbeeInValidTestPoint) != nullptr){
		std::cerr << "const vector<point> & updatemap(Vector<Line> & map,const Point & p) : invalid as location got accepted";
		return 25;
	}
	
	//Test if a mapupdate with a valid parameters is accepted
	if(!s.updatemap(TestMap,RosbeeValidTestPoint) != nullptr){
		std::cerr << "const vector<point> & updatemap(Vector<Line> & map,const Point & p) : valid as location did not got accepted";
		return 26;
	}
	
	std::cout << "All tests succeeded!";
	return 0;
}