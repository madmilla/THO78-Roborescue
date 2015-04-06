#ifndef AIRCS_H
#define AIRCS_H
#include "RobotCS.h"


class AirCS : public RobotCS
{
public:
	AirCS(std::string name, int serialNumber, double OperationRangeKM, double MaxForwardSpeed, double Width, double Hight, double depth, double maxAltitudeInM, double landingStripLengtInM, double runwayLengthInM);
	~AirCS();

	//getters
	double getMaxAltitudeInM();
	double getLandingStripLengtInM();
	double getRunwayLengthInM();
	std::string getJSONstring();
	std::vector<std::string> getSensor();

	//setters
	void setMaxAltitudeInM(double maxAltitudeInM);
	void setLandingStripLengtInM(double landingStripLengtInM);
	void setRunwayLengthInM(double runwayLengthInM);
	void AddSensorModule(std::string ModuleName);


private:
	double _maxAltitudeInM;
	double _landingStripLengtInM;
	double _runwayLengthInM;
	std::vector<std::string> _sensorVector;
};

#endif // AIRCS_H