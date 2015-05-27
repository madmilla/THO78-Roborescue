#ifndef __CPIBOUNDARYOBJECT__
#define __CPIBOUNDARYOBJECT__


#include <cstdint>
#include "Socket.hpp"
#include <iostream>
#include "mingw.thread.h"

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class CPIBoundaryObject
/// \brief A boundary object for all the vehicles in the project, an id is used as identification and a device has socket to communicate over
/// \brief CPiBoundary object is always a thread this thread should be implemented by the subclasses

class CPIBoundaryObject
{
public:

	CPIBoundaryObject(){ 
		
	}
	~CPIBoundaryObject(){}
protected:

	/// \brief Starts implemented robot thread
	void start(){ robotThread = std::thread(&CPIBoundaryObject::run, this); }
	/// \brief Pure virtual getid, this method should return the identifier of boundary object
	/// \return Id of the boundary object
	virtual int getId() = 0;

	/// \brief Robotlogic method this method should be overwritten
	/// \return void
	virtual void run(){}
private:
	std::thread robotThread;
	};
#endif