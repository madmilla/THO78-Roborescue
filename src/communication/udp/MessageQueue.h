/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file MessageQueue
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




#ifndef __MESSAGEQUEUE__
#define __MESSAGEQUEUE__
#include <vector>
#include <algorithm>
#include <cassert>
#include "NonCopyable.h"

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \template MessageQueue
/// \brief A template class for an simple message queue
template <typename T>
class MessageQueue : public NonCopyable{
public:

	/// \param T item add item to queu
	void add(T item){
		container.push_back(item);
	}


	/// \brief asserts if item in queue then returns first item in queue and pops the first record
	/// \return T item
	T pop(){
		assert(!container.empty());
		T rtnVal = container.front();
		container.erase(container.begin());
		return rtnVal;
	}

	/// \brief checks first message in queue
	/// \return T item
	T peek(){
		assert(!container.empty());
		return container.front();
	}


	/// \brief Removes all items from queue
	/// \param T item
	void remove(T key){
		container.erase(std::remove(container.begin(), container.end(), key), container.end());
	}
	

	/// \brief names size of queue
	/// \return size_t size
	size_t size(){
		return container.size();
	}


	/// \brief Checks if queue is empty
	/// \return bool isempty
	bool isEmpty(){
		return container.empty();
	}
private:
	std::vector<T> container;
};

#endif