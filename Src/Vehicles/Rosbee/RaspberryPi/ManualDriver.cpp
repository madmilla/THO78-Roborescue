/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file ManualDriver.cpp
* @date Created: 22-5-2015
*
* @author Nathan Schaaphuizen
* @version 1.0
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided$
* - Redistributions of source code must retain the above copyright notice, this list of conditions and th$
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and$
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors m$
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

#include "ManualDriver.h"
#include <thread>
#include "Keyboard.h"
#include <iostream>

ManualDriver::ManualDriver(RosbeeDriver &driver):
driver{&driver},
thread{&ManualDriver::run,this}
{
	//Separate new thread from the current thread.
	thread.detach();
}

void ManualDriver::run(){
	//Keyboard object used to check key presses.
	Keyboard kb;
	//Speed of left motor.
	int lspeed = 0;
	//Speed of right motor.
	int rspeed = 0;
	//Normal drive speed.
	int speed = 30;
	//Overwrite variable used to enable/disable manual override.
	bool override = false;
	//Run forever, no need to end this loop unless the program quits.
	while(true){
		//Wait 5 ms.
		usleep(5000);
		//Test if the x key is pressed.
		if(kb.isKeyDown('x') && !override){
			//Set override to true.
			override = true;
			//Print a message to let user know manual override is enabled.
			std::cout << "Manual override enabled!" << std::endl;
			//Wait 1 sec to avoid sticky toggle.
			sleep(1);
		}
		//Check if override is enabled.
		//This is not the correct way, but this a debug class anyway.
		if(!override) continue;
		//Test if the x key is pressed.
		if(kb.isKeyDown('x')){
			//Set override to false.
			override = false;
			//Print a message to let user know manual override is disabled.
			std::cout << "Manual override disabled!" << std::endl;
			//Wait 1 sec to avoid sticky toggle.
			sleep(1);
			//Skip to top to avoid other keys being tested.
			//This is not the correct way, but this a debug class anyway.
			continue;
		}

		//Forward and stop
		if(kb.isKeyDown('w')){
			lspeed = speed;
			rspeed = speed;

		}
		else{
			lspeed = 0;
			rspeed = 0;
		}
		//Reverse
		if(kb.isKeyDown('s')){
			lspeed = -speed;
			rspeed = -speed;
		}
		//Left
		if(kb.isKeyDown('a')){
			rspeed = 40;

		}
		//Right
		if(kb.isKeyDown('d')){
			lspeed = 40;
		}
		//Send the drive command.
		driver->forward(lspeed, rspeed);
	}
}

