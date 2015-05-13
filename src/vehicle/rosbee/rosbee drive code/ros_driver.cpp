/*!
 \file    ros_driver.cpp
 \brief   Class to manage the serial port on Linux systems
 \version 1.5
 \date    13 may 2015
*/

#include "ros_driver.h"

// opens port for rosbee
ros_driver::ros_driver(const char* port){
	_port = port;
	if(ls.open(_port, baud) == 1){
		std::cout << "Poort is open" << '\n';
	}else{
		std::cout << "Poort is niet open" << '\n';
	}
}

void ros_driver::closeConnection(){
	ls.close();
}

void ros_driver::stop(){
	std::cout << "write is: " << ls.write(stopCommand.c_str(), maxBytes) << '\n';
	std::cout << "read is: " << ls.read(&test,maxBytes) << '\n';
	
	sleep(sleepTime);
	
	std::cout << "write is: " << ls.write(confirmCommand.c_str(), maxBytes) << '\n';
	std::cout << "read is: " << ls.read(&test,maxBytes) << '\n';
}

void ros_driver::forward(std::string speed){
    std::string command = forwardCommand;
    command+= speed;
	
	std::cout << "write is: " << ls.write(command.c_str(), maxBytes) << '\n';
	std::cout << "read is: " << ls.read(&test,maxBytes) << '\n';
	
	sleep(sleepTime);
	
	std::cout << "write is: " << ls.write(confirmCommand.c_str(), maxBytes) << '\n';
	std::cout << "read is: " << ls.read(&test,maxBytes) << '\n';
}

void ros_driver::rotate(std::string degrees){
	ls.flush();
	std::string command = rotateCommand;
	command+= degrees;
	
	std::cout << "write is: " << ls.write(command.c_str(), maxBytes) << '\n';
	std::cout << "read is: " << ls.read(&test,maxBytes) << '\n';
	
	sleep(sleepTime);
	
	std::cout << "write is: " << ls.write(confirmCommand.c_str(), maxBytes) << '\n';
	std::cout << "read is: " << ls.read(&test,maxBytes) << '\n';
}
