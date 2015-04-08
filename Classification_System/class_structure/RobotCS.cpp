#include "RobotCS.h"



RobotCS::RobotCS(std::string name, int serialNumber, double OperationRangeKM, double MaxForwardSpeed, double Width, double Hight, double depth)
		: _Name(name), _OperationRangeKM(OperationRangeKM), _MaxForwardSpeed(MaxForwardSpeed), _Width(Width), _Hight(Hight), _depth(depth)

	{
		

	}







//getters
std::string RobotCS::getName(){
	return _Name;
}
double RobotCS::getSerialNumber(){
	return _serialNumber;
}
double RobotCS::getOperationRangeKM(){
	return _OperationRangeKM;
}
double RobotCS::getMaxForwardSpeed(){
	return _MaxForwardSpeed;
}
double RobotCS::getWidth(){
	return _Width;
}
double RobotCS::getHight(){
	return _Hight;
}
double RobotCS::getDepth(){
	return _depth;
}
std::vector<std::string> RobotCS::getSensor(){
	return _sensorVector;
}
std::string RobotCS::getJSONstring(){
	return"TODO: double to stirng for robot";
}

//setters
void RobotCS::setGetName(std::string name){
	_Name = name;
}
void RobotCS::setSerialNumber(double serialNumber){
	_serialNumber = serialNumber;
}
void RobotCS::setOperationRangeKM(double OperationRangeKM){
	_OperationRangeKM = OperationRangeKM;
}
void RobotCS::setMaxForwardSpeed(double MaxForwardSpeed){
	_MaxForwardSpeed = MaxForwardSpeed;
}
void RobotCS::setWidth(double Width){
	_Width = Width;
}
void RobotCS::setHight(double Hight){
	_Hight = Hight;
}
void RobotCS::setDepth(double depth){
	_depth = depth;
}
void RobotCS::AddSensorModule(std::string sensorName){
	_sensorVector.push_back(sensorName);
}