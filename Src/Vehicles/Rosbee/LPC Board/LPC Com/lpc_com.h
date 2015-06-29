/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file propcom.h
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

#ifndef LPCCOM_H
#define LPCCOM_H

#include "lpc_com.h"
#include "libserial.h"
#include "GPIOClass.h"
#include <math.h>

/*! \class LPCCom
    \brief    This class reads ADC values provided through a UART..
              The class allows basic operations (opening the connection, reading and closing the connection).
 */

class LPCCom {
public:

	 // Constructor of the class
	LPCCom(const char* uartPort, const char* gpioPort);
	
	// Destructor of the class
	~LPCCom();
	
	// Configuration and initialization
	bool init();

	// Read data from the UART
	double readData();

private:
	LibSerial* uart;
	GPIOClass* gpio;
	const char* portName;
	int baudRate = 38400;
};

/*!
  \mainpage LPCCom class

  \brief
    The class LibSerial offers a simple way to use the LPC Board created for ADC on the Rosbee.
	Use constructor to setup a object, initialize it to open the ports and then use the readData function as much as needed to get the ADC value's.
	Do not forget to turn off the login shell on the RPI, otherwise this software will not function properly!
*/

#endif
