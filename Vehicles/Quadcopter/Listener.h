#ifndef _LISTENER_H
#define _LISTENER_H

class Subject;

class Listener
{
public:
	virtual void notifyListener(Subject&) = 0;
};
#endif