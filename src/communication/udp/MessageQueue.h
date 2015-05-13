#ifndef __MESSAGEQUEUE__
#define __MESSAGEQUEUE__
#include <vector>
#include <algorithm>
#include <cassert>
#include "NonCopyable.h"

template <typename T>
class MessageQueue : public NonCopyable{
public:
	void add(T item){
		container.push_back(item);
	}

	T pop(){
		assert(!container.empty());
		T rtnVal = container.front();
		container.erase(container.begin());
		return rtnVal;
	}
	T peek(){
		assert(!container.empty());
		return container.front();
	}

	void remove(T key){
		container.erase(std::remove(container.begin(), container.end(), key), container.end());
	}
	
	size_t size(){
		return container.size();
	}
	bool isEmpty(){
		return container.empty();
	}
private:
	std::vector<T> container;
};

#endif