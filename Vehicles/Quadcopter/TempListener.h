#ifndef _TEMPLISTENER_H
#define _TEMPLISTENER_H
#include "Listener.h"
/**
* Temp listener for listening to statusmessages. It will 
*
*/
class TempListener : public Listener
{
public:
	TempListener();
	~TempListener();

	void notifyListener(Subject&, StatusText statusText) override;
};

#endif