/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RobotManager
* @date Created: 27-5-2015
*
* @author Rene Keijzer
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



#ifndef __ROBOTMANAGER__
#define __ROBOTMANAGER__
#include <vector>
#include <exception>
#include <sstream>
#include "Rosbee.h"
#include "Lidar.h"

class UDPSocket;
class Rosbee;
class Lidar;
class RobotManager{
public:
	RobotManager(){}

	void createUDPRobot(UDPSocket * s);

	
	template<typename T>
	T * getRobot(int id){
		for(auto robot: robots){
			auto r = dynamic_cast<T *>(robot);
			if(r != nullptr){
				if(id == r->getId()){
					return r;
				}
			}
		}
		return nullptr;
	}
	
template <typename T>
std::vector<T *> getRobots(){
	std::vector<T *> list;

	for(auto robot : robots){
		auto r = dynamic_cast<T *>(robot);
		if(r != nullptr){
			list.push_back(r);
		}
	}
	return list;
}
	
	template <typename T>
	T * createRobot(UDPSocket * s){
		T * robot= new T(s);
		robots.push_back(robot);
		return robot;
	}

	std::string getDetails();

	int size();
private:
	std::vector<CPIBoundaryObject * > robots;

};
#endif