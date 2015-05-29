#ifndef _XYRECEIVER_H
#define _XYRECEIVER_H
#include "TCPClient.h"
#include "Coordinate.h"

class XYReceiver : public TCPClient
{
public:
	XYReceiver(io_service& service, std::string host, std::string port);
	Coordinate<int> getCoordinate() const;
	int getX() const;
	int getY() const;
private:
	Coordinate<int> coordinate;

	void handleMessage(std::string message) override;
};
#endif