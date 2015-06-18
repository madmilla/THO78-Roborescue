/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file propcom.cpp
* @date Created: 12-4-2015
*
* @author Edwin Koek
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

#include "propcom.h"
#include <iostream>

PropCom::PropCom(std::string port):
com{new LibSerial()}
{
	initiate(port);
}

PropCom::~PropCom(){
	com->close();
	delete com;
}

void PropCom::initiate(std::string port){
	int fd = com->open(port.data(),115200);
	if(fd != 1){
		std::cout << "Opening failed, LibSerial error: " << fd << std::endl;
	}else{
		std::cout << "Opening succesfull" << std::endl;
	}
}

void PropCom::setBrakeSpeed(signed char speed, int motorNr){
	if(-127 <= speed && speed <= 127 &&
			(motorNr == 1 || motorNr == 0)){
		char writeBuffer[2];
		if(motorNr == 1){
			writeBuffer[0] = PPP::SET_BRAKE_SPEED_M1;
		}else if (motorNr == 0){
			writeBuffer[0] = PPP::SET_BRAKE_SPEED_M0;
		}
		writeBuffer[1] = speed;
		com->flush();
		com->writeChar(writeBuffer[0]);
		usleep(1000);
		com->writeChar(writeBuffer[1]);
		usleep(1000);
	}
}

void PropCom::setMotorSpeed(signed char speed, int motorNr){
	if(-127 <= speed && speed <= 127 &&
			(motorNr == 1 || motorNr == 0)){
		char writeBuffer[2];
		if(motorNr == 1){
			writeBuffer[0] = PPP::SET_SPEED_M1;
		}else if (motorNr == 0){
			writeBuffer[0] = PPP::SET_SPEED_M0;
		}
		writeBuffer[1] = speed;
		com->flush();
		com->writeChar(writeBuffer[0]);
		usleep(1000);
		com->writeChar(writeBuffer[1]);
		usleep(1000);
	}
}

int PropCom::getFirmwareVersion(){
	unsigned char readBuffer;
	com->flush();
	com->writeChar(PPP::GET_FIRMWARE_VERSION);
	while(com->peek() < 1){
		usleep(1000);
	}
	com->read(&readBuffer,sizeof(readBuffer));
	usleep(1000);
	return readBuffer;
}

int PropCom::getError(){
	unsigned char readBuffer;
	com->flush();
	com->writeChar(PPP::GET_ERROR);
	while(com->peek() < 1){
		usleep(1000);
	}
	com->read(&readBuffer,sizeof(readBuffer));
	usleep(1000);
	return readBuffer;
}

int PropCom::getPulseCount(int motorNr){
	unsigned char readBuffer[4];
	com->flush();
	if(motorNr == 1){
		com->writeChar(PPP::GET_PULSE_COUNT_M1);
	}else if(motorNr == 0){
		com->writeChar(PPP::GET_PULSE_COUNT_M0);
	}
	while(com->peek() < 4){
		usleep(1000);
	}
	com->read(readBuffer,sizeof(readBuffer));
	usleep(1000);
	return *reinterpret_cast<int*>(readBuffer);
}

int PropCom::getPulseSpeed(int motorNr){
	unsigned char readBuffer;
	com->flush();
	if(motorNr == 1){
		com->writeChar(PPP::GET_PULSE_SPEED_M1);
	}else if(motorNr == 0){
		com->writeChar(PPP::GET_PULSE_SPEED_M0);
	}
	while(com->peek() < 1){
		usleep(1000);
	}
	com->read(&readBuffer,sizeof(readBuffer));
	usleep(1000);
	return readBuffer;
}

int PropCom::getDistance(int ultraSonicSensorNr){
	unsigned char readBuffer[4];
	com->flush();
	switch(ultraSonicSensorNr){
	case(0):
			com->writeChar(PPP::GET_DISTANCE_S0);
			break;
	case(1):
			com->writeChar(PPP::GET_DISTANCE_S1);
			break;
	case(2):
			com->writeChar(PPP::GET_DISTANCE_S2);
			break;
	case(3):
			com->writeChar(PPP::GET_DISTANCE_S3);
			break;
	case(4):
			com->writeChar(PPP::GET_DISTANCE_S4);
			break;
	case(5):
			com->writeChar(PPP::GET_DISTANCE_S5);
			break;
	}
	while(com->peek() < 4){
		usleep(1000);
	}
	com->read(readBuffer,sizeof(readBuffer));
	usleep(1000);
	return *reinterpret_cast<int*>(readBuffer);
}


void PropCom::sendData(unsigned char command, unsigned char value){
	unsigned char writeBuffer[2];
	writeBuffer[0] = command;
	writeBuffer[1] = value;
	com->flush();
	com->write(writeBuffer,sizeof(writeBuffer));
	usleep(1000);
}

std::vector<unsigned char> PropCom::readData(unsigned char command, int returnedBytes){
	unsigned char readBuffer[returnedBytes];
	com->flush();
	com->writeChar(command);
	while(com->peek() < returnedBytes){
		usleep(1000);
	}
	com->read(readBuffer, returnedBytes);
	usleep(1000);
	std::vector<unsigned char> returnBuffer;
	for(int i = 0; i < returnedBytes; ++i){
		returnBuffer[i] = readBuffer[i];
	}
	return returnBuffer;
}


