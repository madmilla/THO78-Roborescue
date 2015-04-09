#include <stdint>
#include "SocketListener.hpp"
class CPIBoundaryObject : public SocketListener
{
public:
	CPIBoundaryObject(Socket sock, Uint32_t id) : SocketListener(sock, id), socket(socket), DeviceId(id){}
	virtual void sendCommand(Command cmd);
	~CPIBoundaryObject(){}
private:
	u_int32 DeviceId;
	Socket socket;
};