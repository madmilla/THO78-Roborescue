#include <cstdint>
#include "SocketListener.hpp"
class CPIBoundaryObject
{
public:
	CPIBoundaryObject(Socket sock, uint16_t id) :  socket(socket), DeviceId(id){}
	virtual void sendCommand(Command cmd);
	~CPIBoundaryObject(){}
private:
	uint16_t DeviceId;
	Socket socket;
};