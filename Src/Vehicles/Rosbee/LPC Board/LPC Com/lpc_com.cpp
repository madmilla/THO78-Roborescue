/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file lpc_com.cpp
* @date Created: 21-6-2015
*
* @author Kyle Taylor Parkins
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

#include "lpc_com.h"

using namespace std;

LPCCom::LPCCom(const char* uartPort, const char* gpioPort) {
	uart = new LibSerial();
	gpio = new GPIOClass(gpioPort);
	portName = uartPort;
}

LPCCom::~LPCCom(){
	uart->close();
	delete uart;
	gpio->unexport_gpio();
	delete gpio;
}

bool LPCCom::init(){
	gpio->export_gpio(); // export GPIO
	gpio->setdir_gpio("out"); // GPIO set to output
	cout << "GPIO operations done" << endl;

	int portResult = uart->open(portName, baudRate);
	if (portResult != 1){
		std::cout << "Opening failed, error:" << portResult << endl;
		return false;
	}else{
		std::cout << "Opening succesfull" << endl;
		return true;
	}
}
double LPCCom::readData(){
	gpio->setval_gpio("1");
	usleep(20 * 1000);
	gpio->setval_gpio("0");
    char* data;
	uart->read(data, 4);
    cout << "read from port: " << data << endl;
    return atof(data);
}
