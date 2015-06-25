#ifndef _SERIAL_PORT_H
#define _SERIAL_PORT_H
#include <memory>
#include <boost/asio.hpp>
using namespace boost;

class SerialPort
{
	
public:
	explicit SerialPort(asio::io_service& service);
	~SerialPort();
	bool open(std::string portname, int baudRate);
	size_t readData(unsigned char* buffer, int nrOfBytes);
	size_t writeData(unsigned char* buffer, int nrOfBytes);
private:
	asio::io_service& service;
	std::shared_ptr<asio::serial_port> port;
};
#endif