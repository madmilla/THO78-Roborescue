#include "SerialPort.h"
#include <iostream>

SerialPort::SerialPort(asio::io_service& service):
service{ service }
{
}

SerialPort::~SerialPort()
{
	if (port != nullptr)
	{
		port->cancel();
		port->close();
	}
}

bool SerialPort::open(std::string portname, int baudRate)
{
	if (port != nullptr)
	{
		std::cerr << "Port was already opened" << std::endl;
		return false;
	}
	port = std::make_shared<asio::serial_port>(asio::serial_port{ service });
	system::error_code errorCode;
	if (errorCode)
	{
		std::cerr << "Error while opening port: " + errorCode.message() << std::endl;
		return false;
	}
	port->open(portname, errorCode);
	port->set_option(asio::serial_port_base::baud_rate(baudRate));
	port->set_option(asio::serial_port_base::character_size(8));
	port->set_option(asio::serial_port_base::stop_bits(asio::serial_port_base::stop_bits::one));
	port->set_option(asio::serial_port_base::parity(asio::serial_port_base::parity::none));
	port->set_option(asio::serial_port_base::flow_control(asio::serial_port_base::flow_control::none));
	return true;
}

size_t SerialPort::readData(unsigned char* buffer, int nrOfBytes)
{
	return asio::read(*port, asio::buffer(buffer, nrOfBytes));
}

size_t SerialPort::writeData(unsigned char* buffer, int nrOfBytes)
{
	return asio::write(*port, asio::buffer(buffer, nrOfBytes));
}