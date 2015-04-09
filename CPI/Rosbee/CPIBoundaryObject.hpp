#include <cstdint>
#include "SocketListener.hpp"
class CPIBoundaryObject
{
public:
	CPIBoundaryObject(Socket sock, uint16_t id) :  socket(socket), DeviceId(id){}
	virtual void sendCommand(Command cmd);
	~CPIBoundaryObject(){}
protected:
	Socket socket;
private:
	uint16_t DeviceId;
	
};