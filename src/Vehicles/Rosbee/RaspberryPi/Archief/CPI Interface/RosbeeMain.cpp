#include "RosbeeClient.h"
#include <iostream>
#include <string.h>

using namespace std;
const string ip = "192.168.1.2";

int main(int argc, char **argv) {
	bool enabled = false;
	string temp;
	
	RosbeeClient rc(ip);
	//ChrisObject co;

	std::cout << "Objects created\n";
	
	rc.sendMessage("READY");
	temp = rc.waitReceiveMessage();
	if (temp == "GO") {
		enabled = true;
	}
	std::cout << "Starting receive loop\n";
	while(enabled) {
		temp = rc.waitReceiveMessage(); 
		/*
		if(!co.drive(temp)) {
			co.drive(temp);
		}
		*/
		rc.sendMessage("DONE");
		std::cout << "Receiving done\n";
	}
	std::cout << "Back in main, should only happen on exit\n";
}