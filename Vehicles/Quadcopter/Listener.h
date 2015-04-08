#ifndef _LISTENER_H
#define _LISTENER_H
#include "StatusText.h"
class Subject;

class Listener
{
public:
	virtual void notifyListener(Subject&, StatusText statusText) = 0;
};
#endif