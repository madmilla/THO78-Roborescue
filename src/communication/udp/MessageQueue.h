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