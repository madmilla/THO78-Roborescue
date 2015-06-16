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
#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"

int main()
{
	UDPClient sock;
	CPIConnector cp;
	sock.addListener(&cp);

	while(true){
		std::cout << "Main" << std::endl;
		sleep(1);
	}
}
