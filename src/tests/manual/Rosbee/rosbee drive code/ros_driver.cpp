/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file ros_driver.cpp
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
