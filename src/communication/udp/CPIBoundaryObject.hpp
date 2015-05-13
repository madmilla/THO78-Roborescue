#ifndef __CPIBOUNDARYOBJECT__
#define __CPIBOUDNARYOBJECT__


#include <cstdint>
#include "Socket.hpp"
#include <iostream>
#include "mingw.thread.h"

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class CPIBoundaryObject
/// \brief A boundary object for all the vehicles in the project, an id is used as identification and a device has socket to communicate over

class CPIBoundaryObject
{
public:
	/// \param socket to communicate over
	/// \param id for identification
	CPIBoundaryObject(Socket sock) :  socket(socket){
		DeviceId = socket.getId(); 
		robotThread = std::thread(&CPIBoundaryObject::run, this);
	}
	~CPIBoundaryObject(){}
protected:
	virtual void run() = 0;
	Socket socket;
private:
	uint16_t DeviceId;
	std::thread robotThread;
	};
#endif