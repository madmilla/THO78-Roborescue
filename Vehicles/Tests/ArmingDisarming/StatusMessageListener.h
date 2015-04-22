#ifndef _STATUSMESSAGELISTENER_H
#define _STATUSMESSAGELISTENER_H
#include "Listener.h"
/**
* StatusMessage listener for listening to statusmessages. It will listen for 
* notifications from the quadcopter and print them in the console.
* @author Feiko Wielsma
*
*/
class StatusMessageListener : public Listener
{
public:
	StatusMessageListener();
	~StatusMessageListener();

	void notifyListener(Subject&, StatusText statusText) override;
};

#endif