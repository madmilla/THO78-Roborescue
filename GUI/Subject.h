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

    //TBC
    void unregisterListener(Listener* listener)
    {

    }
protected:
	void notifyListeners(StatusText statusText)
	{
		for(auto& listener : listeners)
		{
			listener->notifyListener(*this, statusText);
		}
	}
	std::vector<Listener*> listeners;
};
#endif
