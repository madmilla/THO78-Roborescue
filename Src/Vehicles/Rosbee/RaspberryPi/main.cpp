#include "RosbeeDriver.h"

#include <string>
#include <iostream>
#include <thread>

#include "Keyboard.h"
#include "PositionController.h"

#include "PropCom.h"
#include "RosbeeClient.h"

#include "ManualDriver.h"
#include "RosbeeProtocolHandler.h"


int main(){

	PropCom propCom;
	propCom.open("/dev/ttyUSB0");


	PositionController positionController{&propCom};
	RosbeeDriver rosbeeDriver{propCom, positionController};
	ManualDriver manualDriver{rosbeeDriver};


	RosbeeClient rosbeeClient{"192.168.1.2", 8888};

	RosbeeProtocolHandler rosbeeProtocolHandler{rosbeeClient,positionController,rosbeeDriver};

	
	while(true){sleep(1);}
	return 0;
}
