#ifndef _SERIAL_CONNECTION_H
#define _SERIAL_CONNECTION_H
#include "DataPort.h"
#include <memory>
#include <boost/asio.hpp>
using namespace boost;

class SerialConnection : public DataPort, public asio::serial_port
{
	
public:
	explicit SerialConnection(asio::io_service& service);
	~SerialConnection();
	bool open(std::string portname, int baudRate);
	size_t readData(unsigned char* buffer, int nrOfBytes) override;
	size_t writeData(const unsigned char* buffer, int nrOfBytes) override;
private:
	asio::io_service& service;
};
#endif