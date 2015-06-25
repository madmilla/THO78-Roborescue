//============================================================================
// Name        : UDP2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <stdlib.h>
#include "UDPClient.h"
#include "CPIConnector.h"
#include "roborescueV1/mavlink.h"

#define SLEEP 1

int main()
{
	UDPClient sock;
	CPIConnector cp;
	sock.setBaseRobot(&cp);

	while(true){
		std::cout << "Main" << std::endl;
		sleep(SLEEP);
	}
}
