#include "CPIBoundaryObject.h"
#include "UDPSocket.h"
#include "RALCPEncoder.h"
#include "MessageQueue.h"
#include "roborescueV1/mavlink.h"

#ifndef __UDPROBOT__
#define __UDPROBOT__


class CPIUDPSocket;
class UDPRobot : public CPIBoundaryObject{

public:
	UDPRobot(CPIUDPSocket * s);
	~UDPRobot(){ delete encoder; delete sock; }
private:
protected:
	virtual void run(){} 
	virtual int getId() = 0;
	CPIUDPSocket * sock;
	mavlink_message_t message;
	//mavlink_ralcp_t packet;
	RALCPEncoder * encoder;
};
#endif