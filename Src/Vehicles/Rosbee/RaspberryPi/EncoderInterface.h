/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file EncoderInterface.h
* @date Created: 15-6-2015
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


#ifndef ENCODERINTERFACE_H_
#define ENCODERINTERFACE_H_

#include "PropCom.h"
/**
 *@brief EncoderInterface Class
 *
 * This class manages the encoders. It provides functions that 
 * allow easy usage and management of encoder data.
 */
class EncoderInterface {
public:
/**
 *@brief EncoderInterface constructor
 *@param PC is the propeller communicator
 *@param encoderNr defines wether your are reading the left or right encoder. 1 is left, 0 is right.
 */
	EncoderInterface(PropCom* PC, int encoderNr);
/**
 *@brief Starts the encoder count.
 */
	void startCount();
/**
 *@brief Returns the accumulated encoder count
 *@returns The total encoder count since startCount was called.
 */
	int getCount();
/**
 *@brief Returns the delta count
 *@returns Returns the change in encoder count since last call of this function
 */
	int deltaCount();

private:
	PropCom* m_PC;

	int m_encoderNr;

	int encoderCount;
};

#endif
