#ifndef _XYRECEIVER_H
#define _XYRECEIVER_H
#include "TCPClient.h"
#include "Coordinate.h"

class XYReceiver : public TCPClient
{
public:
	XYReceiver(io_service& service, std::string host, std::string port);

	/**
	* \brief Get coordinate.
	*
	* Get the most recent received coordinate. The coordinate values are integers.
	*
	* \return coordinate Most recent coordinate.
	*/
	Coordinate<int> getCoordinate() const;

	/**
	* \brief Get X position coordinate.
	*
	* Get the X position from the most recent received coordinate.
	*
	* \return x X position from the most recent coordinate.
	*/
	int getX() const;

	/**
	* \brief Get Y position coordinate.
	*
	* Get the Y position from the most recent received coordinate.
	*
	* \return y Y position from the most recent coordinate.
	*/
	int getY() const;
private:
	Coordinate<int> coordinate;

	void handleMessage(std::string message) override;
};
#endif