#ifndef _SUBJECT_H
#define _SUBJECT_H
#include "Listener.h"
#include <vector>

class Subject
{
public:
	void registerListener(Listener* listener)
	{
		listeners.push_back(listener);
	}
protected:
	void notifyListeners()
	{
		for(auto& listener : listeners)
		{
			listener->notifyListener(*this);
		}
	}
	std::vector<Listener*> listeners;
};
#endif