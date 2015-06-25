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
	/*
	int stats = propCom.open("/dev/ttyUSB0");
	if(stats != 1){
		std::cout << "Opening failed, LibSerial error: " << stats << std::endl;
	}
	else{
		std::cout << "Opening succesfull" << std::endl;
	}
    */
	RosbeeDriver driver{propCom};

/*******************************test case 1******************************************************************************/
	// laat rosbee een vierkant rijden:
	driver.drive(20);
	driver.rotate(90);
	driver.drive(20);
	driver.rotate(90);
	driver.drive(20);
	driver.rotate(90);
	driver.drive(20);

/*******************************test case 2******************************************************************************/
	// laat hem naar een object rijden en dan voor het object stoppen en/ of ontwijken
	driver.driveToWaypoint(500,1000);

/*******************************test case 3******************************************************************************/
	// laat de rosbee een stuk naar voren rijden, weer terug en dan weer naar voren
	driver.drive(20);
	driver.rotate(180);
	driver.drive(20);
	driver.rotate(180);
	driver.drive(20);

/*******************************test case 4******************************************************************************/
	// laat de rosbee naar een waypoint rijden
	driver.driveToWaypoint(500,1000);
/*************************************************************************************************************************/
}
