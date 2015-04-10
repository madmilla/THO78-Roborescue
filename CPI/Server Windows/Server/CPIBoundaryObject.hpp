#ifndef __CPIBOUNDARYOBJECT__
#define __CPIBOUDNARYOBJECT__


#include <cstdint>
#include "Socket.hpp"

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class CPIBoundaryObject
/// \brief A boundary object for all the vehicles in the project, an id is used as identification and a device has socket to communicate over

class CPIBoundaryObject
{
public:
	/// \param socket to communicate over
	/// \param id for identification
	CPIBoundaryObject(Socket sock, uint16_t id) :  socket(socket), DeviceId(id){}
	~CPIBoundaryObject(){}
protected:
	Socket socket;
private:
	uint16_t DeviceId;
	
	};

#endif // !__CPIBOUNDARYOBJECT__
