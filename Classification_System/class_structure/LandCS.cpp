#include "LandCS.h"

LandCS::LandCS(std::string name, int serialNumber, double OperationRangeKM, double MaxForwardSpeed, double Width, double Hight, double depth, double turningRadiusInM) 
: RobotCS(name, serialNumber, OperationRangeKM, MaxForwardSpeed, Width, Hight, depth), _turningRadiusInM(turningRadiusInM)
	{ 

	}
//getters
std::vector<std::string> LandCS::getSensor(){
	return _sensorVector;
}
std::string LandCS::getJSONstring(){
	return"TODO: double to stirng for LAND robot";
}
double LandCS::getTurningRadiusInM(){
	return _turningRadiusInM;
}

//setters
void LandCS::AddSensorModule(std::string sensorName){
	_sensorVector.push_back(sensorName);
}
void LandCS::setTurningRadiusInM(double turningRadiusInM){
	_turningRadiusInM = turningRadiusInM;
}

