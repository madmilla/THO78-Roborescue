#ifndef _TCPCLIENT_H
#define _TCPCLIENT_H
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace ip;

class TCPClient
{
public:
	virtual ~TCPClient();
	TCPClient(io_service& service, std::string host, std::string port);
private:
	tcp::resolver::query tcpQuery;
	tcp::resolver tcpResolver;
	tcp::endpoint tcpEndpoint;
	tcp::socket tcpSocket;
	streambuf receiveBuffer;

	/**
	* \brief Handler which is called once the io_service is done
	* resolving the connection.
	*
	* This method should not be called by the user, it is a handler method
	* which is called by the io_service once it is done asynchronously
	* resolving the connection.
	*
	* \param ec Error code containing information about possible errors that have occured.
	* \param it An iterator object pointing to an endpoint containing connection data.
	*/
	void connectionResolvedHandler(const boost::system::error_code &ec, tcp::resolver::iterator it);

	/**
	* \brief Handler which is called once the io_service is done establishing
	* the connection.
	*
	* This method should not be called by the user, it is a handler method
	* which is called by the io_service once it is done asynchronously
	* establishing the connection.
	*
	* \param ec Error code containing information about possible errors that have occured.
	*/
	void connectedHandler(const boost::system::error_code &ec);

	/**
	* \brief Starts asynchronously reading data from the socket.
	*
	* Tells the io_service to start asynchronously reading data from
	* the socket until a newline character ('\n') has been read 
	* and call dataReceivedHandler() once it has done so.
	*/
	void readData();

	/**
	* \brief Handler which is called once data has been read by the io_service.
	*
	* This method should not be called by the user, it is a handler method
	* which is called by the io_service once it's done asynchronously 
	* reading data from the socket.
	*
	* When data has succesfully been received it will proceed
	* to call handleMessage() to further handle the data and call 
	* readData() to start reading data again.
	*
	* \param ec Error code containing information about possible errors that have occured.
	* \param
	*/
	void dataReceivedHandler(const boost::system::error_code &ec, size_t bytesTransferred);

protected:

	/**
	* \brief Pure virtual which defines the way received messages are handled.
	*
	* \param message A string containing the message to be handled.
	*/
	virtual void handleMessage(std::string message) = 0;
};
#endif