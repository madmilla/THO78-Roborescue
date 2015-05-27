//============================================================================
// Name        : UDP2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


#include "PracticalSocket.h"
#include <iostream>
#include <inttypes.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "UDPClient.h"
#include "CPIConnector.h"
#include "mavlink/udp_mavlink_commands/mavlink.h"

int main(int argc, char **argv)
{
	UDPClient sock;
	CPIConnector cp{1};
	sock.addListener(&cp);

	while(true){
		std::cout << "Main" << std::endl;
		sleep(1);
	}
}
