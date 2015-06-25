/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Keyboard.cpp
* @date Created: 17-5-2015
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
#include "Keyboard.h"
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>

Keyboard::Keyboard():
thread{&Keyboard::run,this}
{
	//Detach the thread from the current thread.
	thread.detach();
	//Set all the keys to false. We just assume they're not pressed when the
	//program starts.
	for(unsigned int i = 0; i < sizeof(keysDown); i++){
		keysDown[i] = false;
	}
	//Use termios to turn off line buffering.
	//I have no clue what the stuff below actually does.
	//Just take it that it works this way.
	termios term;
	tcgetattr(STDIN, &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(STDIN, TCSANOW, &term);
	setbuf(stdin, NULL);
}

bool Keyboard::isKeyDown(int key){
	//Return the key down value.
	return keysDown[key];
}

bool Keyboard::isKeyUp(int key){
	//Return the key up value.
	return !keysDown[key];
}

void Keyboard::run(){
	//Variable used to store the amount of bytes waiting in the stream.
	int bytesWaiting;
	//Variable used to read the a byte from stream
	char c;
	//Variable to hold a relative time, we start at 0.
	int time = 0;
	//Run forever, there is no need to stop this loop unless you close the program.
	while(true){
		//Get the amount of bytes waiting in the input stream.
		//And store this number in bytesWaiting.
		ioctl(STDIN, FIONREAD, &bytesWaiting);
		//For every byte waiting:
		for(int i=0; i<bytesWaiting; i++){
			//Read the byte from stream.
			std::cin >> c;
			//Set key down to true.
			//If the byte was in the stream that means the key must have been
			//recently pressed.
			keysDown[(int)c] = true;
			//Set the time stamp.
			timeDown[(int)c] = time;
		}
		//Empty the stream to get rid of all control, whitespace, and other stuff.
		fflush(stdin);
		//For all the keys:
		for(unsigned int i=0; i<keyAmount; i++){
			//Check if 200 ms has passed since the key last appeared in the stream.
			//If so the key has not been held down for a while.
			if( time >= timeDown[i]+200){
				//Set key down to false.
				keysDown[i] = false;
			}
		}
		//Update the time.
		time++;
		//Wait 1 ms.
		usleep(1000);
	}
}
