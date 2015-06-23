#ifndef ROS_CONTROL_HPP
#define ROS_CONTROL_HPP

#include <stdio.h> // standard input / output functions
#include <string.h> // string function definitions
#include <unistd.h> // UNIX standard function definitions
#include <fcntl.h> // File control definitions
#include <errno.h> // Error number definitions
#include <termios.h> // POSIX terminal control definitionss
#include <time.h>   // time calls
#include <iostream>

class rosbee_driver {
public:
	rosbee_driver(std::string port);
	
	void forward(int speed);
	void stop();
	void rotate(int degrees);
	

private:
	void send_command(std::string command, std::string port);
	std::string _port;
};


#endif
