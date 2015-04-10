#ifndef __CPIBOUNDARYOBJECT__
#define __CPIBOUDNARYOBJECT__


#include <cstdint>
#include "Socket.hpp"
class CPIBoundaryObject
{
public:
	CPIBoundaryObject(Socket sock, uint16_t id) :  socket(socket), DeviceId(id){}
	~CPIBoundaryObject(){}
protected:
	Socket socket;
private:
	uint16_t DeviceId;
	
	};

#endif // !__CPIBOUNDARYOBJECT__
