//============================================================================
// Name        : RosbeeTest.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "RosbeeDriver.h"

#include <string>
#include <iostream>
#include <thread>

#include "PositionController.h"
#include "PropCom.h"

int main(){

	PropCom propCom;
	propCom.open("/dev/ttyUSB0");

	RosbeeDriver driver{propCom};

/*******************************test case 1******************************************************************************/
	// laat rosbee een vierkant rijden:
	driver.drive(200);
	driver.rotate(90);
	driver.drive(200);
	driver.rotate(90);
	driver.drive(200);
	driver.rotate(90);
	driver.drive(200);

/*******************************test case 2******************************************************************************/
	// laat hem naar een waypoint rijden 
	driver.driveToWaypoint(500,1000);

/*******************************test case 3******************************************************************************/
	// laat de rosbee naar een waypoint rijden en dan voor een object stoppen en/ of ontwijken
	driver.driveToWaypoint(500,1000);
/*************************************************************************************************************************/
}
