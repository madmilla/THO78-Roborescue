#ifndef ROS_DRIVER_H
#define ROS_DRIVER_H

#include "libserial.h"
#include <string.h> // string function definitions
#include <iostream> //heb misschien niet nodig

/**
 * Summary:
 * 	- A port is openened. Allowing for serial communication.
 * 	- Serial commands are send to the rosbee.
 * 	- The commands send are $1,x (forward at x speed)
 * 	  and $3,y (rotate y degrees).
 * 	- $999, is send to confirm the command.
 *	- $0, is send to stop the rosbee (shutdown)
 **/

 /*! \class ros_driver
    \brief    This class can manage the basic command for the rosbee
              The class allows basic operations (driving forward, rotate, stop, close the serial connection and open the serial connection).
 */
 
class ros_driver{
	public:
	
	/**
	* the constructor of this class, open the connection to the rosbee.
	* @param port the port which the rosbee connects to.
	**/
	ros_driver(const char* port);

	/**
	* closes the connection with the rosbee
	**/
	void closeConnection();
	
	/**
	* sends the stopCommand to stop the rosbee
	**/
	void stop();
	
	/**
	* sends the forwardCommand to let the rosbee drive at x speed
	* @param speed the speed of the rosbee
	**/
	void forward(std::string speed);
	
	/**
	* sends the rotateCommand to rotate the rosbee at x degrees
	* @param degrees the amount of degrees the rosbee will rotate
	**/
	void rotate(std::string degrees);

	private:
	/**
	* the object from the libserial class.
	* used for the connection with the rosbee
	**/
	LibSerial ls;
	
	/**
	* the port on which the rosbee connects to
	**/
	const char* _port;

	/**
	* the command used to drive forward
	**/
	std::string forwardCommand = "$1,";
	
	/**
	* the command used to rotate
	**/
	std::string rotateCommand = "$3,";
	
	/**
	* the command used to stop
	**/
	std::string stopCommand = "$0,";
	
	/**
	* the command used to confirm the commands send
	**/
	std::string confirmCommand = "$999,";
	
	/**
	* the baudrate of the rosbee
	**/
	unsigned int baud = 115200;
	
	/**
	* the max amount of bytes the rosbee will send
	**/
	unsigned int maxBytes = 10; // dit moet groter zijn dan het aantal bytes dat je stuurt.
	
	/**
	* the array which will recive all the bytes read from the buffer
	**/
	char readBytes[10];

};
#endif
