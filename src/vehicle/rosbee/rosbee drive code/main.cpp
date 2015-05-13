#include "ros_driver.h"
#include <string>
#include <iostream>

int main(){
	ros_driver ros("/dev/ttyUSB0");

		ros.forward("25");
		sleep(10);
	
		std::cout << "speed to null" << '\n';
	
		ros.forward("0");
		sleep(10);
		
		std::cout << "speed to 100" << '\n';
	
		ros.forward("100"); //max speed is 127
		sleep(10);
		
		std::cout << "en dan nu stoppen" << '\n';
		
		ros.stop();
		sleep(1);
	
	std::cout << "end of programm" << '\n';
	ros.closeConnection();
	return 0;
}



