/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Keyboard.h
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

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <thread>


/// @brief Class for key handling.
///
/// This class is used to determine if a key is pressed (or not).
/// For this it makes use of the standard input (stdin) and can be used without
/// additional dependencies or drivers.
/// The input from the input stream on it's own thread, therefore it is
/// advised to make only one instance of this class.
class Keyboard {
	//Amount of key we can handle, 255 should suffice for any type of keyboard.
	static const int keyAmount = 255;
	//Array to save keys that are pressed.
	bool keysDown[keyAmount];
	//Array to save the time keys are pressed.
	int timeDown[keyAmount];
	//Thread
	std::thread thread;
	//Input stream
	static const int STDIN = 0;

	//Helper function, the thread will run this function.
	void run();
public:
	/// @brief Create new Keyboard object.
	Keyboard();

	/// @brief Test if key is held down.
	///
	/// @param key The ascii value of the key to be tested.
	/// @return Returns true if key is down. Returns false if key is not down.
	bool isKeyDown(int key);

	/// @brief Test if key is not held down.
	///
	/// @param key The ascii value of the key to be tested.
	/// @return Returns true if key is not down. Returns false if key is down.
	bool isKeyUp(int key);
};

#endif /* KEYBOARD_H_ */
