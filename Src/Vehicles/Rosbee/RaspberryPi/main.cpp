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


#include "Parser.h"

int main(){

	PropCom propCom;
	propCom.open("/dev/ttyUSB0");
	RosbeeDriver rosbeeDriver{propCom};
	ManualDriver manualDriver{rosbeeDriver};

	PositionController positionController{&propCom};

	RosbeeClient rosbeeClient{"192.168.1.15", 7777};

	RosbeeProtocolHandler rosbeeProtocolHandler{rosbeeClient,positionController,rosbeeDriver};

	
	while(true){sleep(1);}
	return 0;
}
