#ifndef ROBOTCS_H
#define ROBOTCS_H

#include <iostream>
#include <vector>

class RobotCS 
{
public:
	RobotCS(std::string name, int serialNumber, double OperationRangeKM, double MaxForwardSpeed, double Width, double Hight, double depth);
	 ~RobotCS();

	 //getters
	  std::string getName();
	  double getSerialNumber();
	  double getOperationRangeKM();
	  double getMaxForwardSpeed();
	  double getWidth();
	  double getHight();
	  double getDepth();
	  virtual std::vector<std::string> getSensor();
	  virtual std::string getJSONstring();

	 //setters
	  virtual void AddSensorModule(std::string ModuleName);
	  void setGetName(std::string name);
	  void setSerialNumber(double serialNumber);
	  void setOperationRangeKM(double OperationRangeKM);
	  void setMaxForwardSpeed(double MaxForwardSpeed);
	  void setWidth(double Width);
	  void setHight(double Hight);
	  void setDepth(double depth);

private:
	std::string _Name;
	int _serialNumber;
	double _OperationRangeKM;
	double _MaxForwardSpeed;
	double _Width;
	double _Hight;
	double _depth;
	std::vector<std::string> _sensorVector;
	
};

#endif // ROBOTCS_H