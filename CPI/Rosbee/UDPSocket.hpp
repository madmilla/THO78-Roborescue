#include "Connection.hpp"
#include "Socket.hpp"
class UDPSocket : Socket
{
public:
	UDPSocket(Connection c, UDPServer & serv) : con(c), server(serv){}
	void send(MavLinkMessage_t * message) override;
	void receive(MavLinkMessage_t * message) override;
	~UDPSocket();
private:
	friend class UDPServer;
	Connection con;
	UDPServer server;
	std::vector<MavLinkMessage_t> responses;
};