#include "Connection.hpp"
#include "Socket.hpp"

class UDPSocket : Socket
{
public:
	UDPSocket(Connection c, UDPServer & serv) : con(c), server(serv){}
	void send(mavlink_message_t * message) override;
	void receive(mavlink_message_t * message) override;
	~UDPSocket();
private:
	friend class UDPServer;
	Connection con;
	std::vector<mavlink_message_t> responses;
};