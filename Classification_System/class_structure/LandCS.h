#ifndef LANDCS_H
#define LANDCS_H

#include "RobotCS.h"

class LandCS : public RobotCS
{
public:
	LandCS(std::string name, int serialNumber, double OperationRangeKM, double MaxForwardSpeed, double Width, double Hight, double depth, double turningRadiusInM);
	~LandCS();
	//getters
	double getTurningRadiusInM();
	std::string getJSONstring();
	std::vector<std::string> getSensor();

	//setters
	void AddSensorModule(std::string ModuleName);
	void setTurningRadiusInM(double turningRadiusInM);

private:
	double _turningRadiusInM;
	std::vector<std::string> _sensorVector;
};

#endif // LANDCS_H