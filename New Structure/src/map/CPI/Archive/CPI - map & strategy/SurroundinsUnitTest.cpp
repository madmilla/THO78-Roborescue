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

constexpr int caseOneFailed = 1;
constexpr int caseTwoFailed = 2;
constexpr int caseThreefailed = 3;
constexpr int caseFourfailed = 4;
constexpr int caseFivefailed = 5;
constexpr int caseSixfailed = 6;
constexpr int caseSevenfailed = 7;
constexpr int caseEightfailed = 8;
constexpr int caseNinefailed = 9;
constexpr int caseTenfailed = 10;
constexpr int caseElevenfailed = 11;
constexpr int caseTwelvefailed = 12;
constexpr int caseThirteenfailed = 13;
constexpr int caseForteenfailed = 14;
constexpr int caseFifteenfailed = 15;
constexpr int caseSixteenfailed = 16;
constexpr int caseSeventeenfailed = 17;
constexpr int caseEighteenfailed = 18;
constexpr int caseNineteenfailed = 19;
constexpr int caseTwentyfailed = 20;
constexpr int caseTwentyonefailed = 21;
constexpr int caseTwentytwofailed = 22;
constexpr int caseTwentythreefailed = 23;
constexpr int caseTwentyfourfailed = 24;
constexpr int caseTwentyfivefailed = 25;
constexpr int caseTwentysixfailed = 26;
constexpr int allCasesSucceeded = 0;


main()
{
   Surroundings s;
   
   
   //Tests for bool setLocation(
   //                  const Point & position,
   //                  RobotType deviceType, 
   //                  int deviceId
   //               );
   
   //Test if nullptr is accepted for point
   if(s.setLocation(nullptr,1,1))
   {
      std::cerr << "bool setLocation(";
	  std::cerr << "        const Point & position,";
	  std::cerr << "        RobotType deviceType,";
	  std::cerr << "        int deviceId)"; 
      std::cerr << "nullptr as Point got accepted";
      return caseOneFailed;
   }
   
   //Test if values below 0 are accepted as robottype
   if(s.setLocation(Point(0,0),-1,1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "-1 as robottype got accepted";
      return caseTwoFailed;
   }
   
   //Test if values below 0 are accepted as robotid
   if(s.setLocation(Point(0,0),1,-1))
   {
      return caseThreefailed;
   }
   
   //Test if a point beyond its max value is accepted
   if(s.setLocation(maxPoint + Point(1,1),1,1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "overflow in Point got accepted";
      return caseFourfailed;
   }
   
   //Test if a DeviceType beyond its max value is accepted
   if(s.setLocation(Point(0,0),maxDeviceType+1,1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "overflow in Robottype got accepted"; 
      return caseFivefailed;
   }
   
   //Test if a DeviceID beyond its max value is accepted
   if(s.setLocation(Point(0,0),1,maxDeviceId+1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "overflow in Id got accepted";
      return caseSixfailed;
   }
   
   //Test if a Minimum valid point value is accepted
   if(!s.setLocation(Point(0,0),1,1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "Valid min point input did not get accepted";
      return caseSevenfailed;
   }
   
   //Test if a Maxmimum valid point value is accepted
   if(!s.setLocation(maxPoint,1,1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "bValid max point input did not get accepted";
      return caseEightfailed;
   }

   //Test if a Maxmimum valid devicetype value is accepted
   if(!s.setLocation(Point(0,0),maxDeviceType,1))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "Valid max DeviceType input did not get accepted";
      return caseNinefailed;
   }
   
   //Test if a Maxmimum valid deviceid value is accepted
   if(!s.setLocation(Point(0,0),1,maxDeviceId))
   {
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "Valid max DeviceId input did not get accepted";
      return caseTenfailed;
   }
   
   
   //Test if a minimum valid location is correctly remembered
   point p(0,0);
   if(s.setLocation(p,1,1))
   {
      if(p != s.getPosition(1,1)){
	     std::cerr << "bool setLocation(";
         std::cerr << "        const Point & position,";
         std::cerr << "        RobotType deviceType,";
         std::cerr << "        int deviceId)"; 
         std::cerr << "New Min position is not the same as set position";
         return caseTwelvefailed;
      }
   }else{
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "Valid SetLocation did not get accepted";
      return caseElevenfailed;
   }
   
   
   //Test if a maximum valid location is correctly remembered
   if(s.setLocation(maxPoint,1,1))
   {
      if(maxPoint != s.getPosition(1,1)){
	     std::cerr << "bool setLocation(";
         std::cerr << "        const Point & position,";
         std::cerr << "        RobotType deviceType,";
         std::cerr << "        int deviceId)"; 
         std::cerr << "New Max position is not the same as set position";
         return caseForteenfailed;
      }
   }else{
      std::cerr << "bool setLocation(";
      std::cerr << "        const Point & position,";
      std::cerr << "        RobotType deviceType,";
      std::cerr << "        int deviceId)"; 
      std::cerr << "Valid SetLocation did not get accepted";
      return caseThirteenfailed;
   }
   
   
   //Tests for const vector<point> & getCompletePath(
   //                                   const Point & start, 
   //                                   const Point & finish
   //                                );
   
   
   
   //Test if a path is genereted with nullptr any parameters is accepted
   if(s.getCompletePath(nullptr,nullptr) != nullptr){
	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "Empty parameters got accepted";
      return caseFifteenfailed;
   }
   
   //Test if a path is genereted with nullptr as finish point is accepted
   if(s.getCompletePath(Point(0,0),nullptr) != nullptr){
	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "nullptr endpoint got accepted";
      return caseSixteenfailed;
   }
   
   //Test if a path is genereted with nullptr as start point is accepted
   if(s.getCompletePath(nullptr,Point(0,0)) != nullptr){
	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "nullptr startpoint got accepted";
      return caseSeventeenfailed;
   }
   
   //Test if a path is genereted with a invalid start and end is accepted
   if(s.getCompletePath(UnAvailableStartInMap,UnAvailableEndInMap) != nullptr){
	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "Inpropriate parameters got accepted";
      return caseEighteenfailed;
   }
   
   //Test if a path is genereted with a invalid end is accepted
   if(s.getCompletePath(AvailableStartInMap,UnAvailableEndInMap) != nullptr){
	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "Inpropriate Endpoint got accepted";
      return caseNineteenfailed;
   }
   
   //Test if a path is genereted with a invalid start is accepted
   if(s.getCompletePath(UnAvailableStartInMap,AvailableEndInMap) != nullptr){
   	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "Inpropriate Beginpoint got accepted";
      return caseTwentyfailed;
   }
   
   //Test if a path is genereted with a valid start and end is accepted
   if(!s.getCompletePath(AvailableStartInMap,AvailableEndInMap) != nullptr){
   	  std::cerr << "bool getCompletePath(";
      std::cerr << "        const Point & start,";
      std::cerr << "        const Point & finish)";
      std::cerr << "Appropriate parameters did not get accepted";
      return caseTwentyonefailed;
   }
   
   
   //Tests for const vector<point> & updatemap(Vector<Line> & map,const Point & position);
   
   
   //Test if a mapupdate with a nullptr as maplines is accepted
   if(s.updatemap(nullptr,RosbeeValidTestPoint) != nullptr){
   	  std::cerr << "const vector<point> & updatemap(";
      std::cerr << "                         Vector<Line> & map,";
      std::cerr << "                         const Point & position)";
      std::cerr << "nullptr as map got accepted";
      return caseTwentytwofailed;
   }
   
   //Test if a mapupdate with a nullptr as position is accepted
   if(s.updatemap(TestMap,nullptr) != nullptr){
      std::cerr << "const vector<point> & updatemap(";
      std::cerr << "                         Vector<Line> & map,";
      std::cerr << "                         const Point & position)";
      std::cerr << "nullptr as location got accepted";
      return caseTwentythreefailed;
   }
   
   //Test if a mapupdate with a nullptr as both parameters
   if(s.updatemap(nullptr,nullptr) != nullptrptr){
      std::cerr << "const vector<point> & updatemap(";
      std::cerr << "                         Vector<Line> & map,";
      std::cerr << "                         const Point & position)";
      std::cerr << "nullptr as both parameters got accepted";
      return caseTwentyfourfailed;
   }
   
   //Test if a mapupdate with a invalid position is accepted
   if(s.updatemap(TestMap,RosbeeInValidTestPoint) != nullptr){
      std::cerr << "const vector<point> & updatemap(";
      std::cerr << "                         Vector<Line> & map,";
      std::cerr << "                         const Point & position)";
      std::cerr << "invalid as location got accepted";
      return caseTwentyfivefailed;
   }
   
   //Test if a mapupdate with a valid parameters is accepted
   if(!s.updatemap(TestMap,RosbeeValidTestPoint) != nullptr){
      std::cerr << "const vector<point> & updatemap(";
      std::cerr << "                         Vector<Line> & map,";
      std::cerr << "                         const Point & position)";
      std::cerr << "valid as location did not got accepted";
      return caseTwentysixfailed;
   }
   
   std::cout << "All tests succeeded!";
   return allCasesSucceeded;
}