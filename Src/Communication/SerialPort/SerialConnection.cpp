#include "SerialConnection.h"
#include <iostream>

SerialConnection::SerialConnection(asio::io_service& service):
asio::serial_port{ service },
service{ service }
{
}

SerialConnection::~SerialConnection()
{
	cancel();
	close();
}

bool SerialConnection::open(std::string portname, int baudRate)
{
	system::error_code errorCode;
	asio::serial_port::open(portname, errorCode);
	set_option(asio::serial_port_base::baud_rate(baudRate));
	set_option(asio::serial_port_base::character_size(8));
	set_option(asio::serial_port_base::stop_bits(asio::serial_port_base::stop_bits::one));
	set_option(asio::serial_port_base::parity(asio::serial_port_base::parity::none));
	set_option(asio::serial_port_base::flow_control(asio::serial_port_base::flow_control::none));
	return true;
}

size_t SerialConnection::readData(unsigned char* buffer, int nrOfBytes)
{
	return asio::read(*this, asio::buffer(buffer, nrOfBytes));
}

size_t SerialConnection::writeData(const unsigned char* buffer, int nrOfBytes)
{
	return asio::write(*this, asio::buffer(buffer, nrOfBytes));
}