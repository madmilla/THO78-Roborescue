/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file ros_driver.h
* @date Created: 13-05-2015
*
* @author Stefan Dijkman
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

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
