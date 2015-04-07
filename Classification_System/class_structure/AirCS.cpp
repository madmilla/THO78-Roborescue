#include "AirCS.h"


AirCS::AirCS(std::string name, int serialNumber, double OperationRangeKM, double MaxForwardSpeed, double Width, double Hight, double depth,double maxAltitudeInM,double landingStripLengtInM, double runwayLengthInM) 
: RobotCS(name,serialNumber,OperationRangeKM, MaxForwardSpeed, Width, Hight, depth)
	{

	}


//getters
double AirCS::getMaxAltitudeInM(){
	return _maxAltitudeInM;
}
double AirCS::getLandingStripLengtInM(){
	return _landingStripLengtInM;
}
double AirCS::getRunwayLengthInM(){
	return _runwayLengthInM;
}
std::string AirCS::getJSONstring(){
	return"TODO: double to stirng for AIR robot";
}
std::vector<std::string> AirCS::getSensor(){
	return _sensorVector;
}

//setters
void AirCS::setMaxAltitudeInM(double maxAltitudeInM){
	_maxAltitudeInM = maxAltitudeInM;
}
void AirCS::setLandingStripLengtInM(double landingStripLengtInM){
	_landingStripLengtInM = landingStripLengtInM;
}
void AirCS::setRunwayLengthInM(double runwayLengthInM){
	_runwayLengthInM = runwayLengthInM;
}

void AirCS::AddSensorModule(std::string sensorName){
	_sensorVector.push_back(sensorName);
}