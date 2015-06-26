#ifndef _XYLocalisationModule_H
#define _XYLocalisationModule_H
#include "TCPClient.h"
#include "Coordinate.h"

class XYLocalisationModule : public TCPClient
{
public:
	XYLocalisationModule(io_service& service, std::string host, std::string port);

	/**
	* \brief Get coordinate.
	*
	* Get the most recent received coordinate. The coordinate values are integers.
	*
	* \return coordinate Most recent coordinate.
	*/
	Coordinate<double> getCoordinate() const;

	/**
	* \brief Get X position coordinate.
	*
	* Get the X position from the most recent received coordinate.
	*
	* \return x X position from the most recent coordinate.
	*/
	double getX() const;

	/**
	* \brief Get Y position coordinate.
	*
	* Get the Y position from the most recent received coordinate.
	*
	* \return y Y position from the most recent coordinate.
	*/
	double getY() const;
private:
	Coordinate<double> coordinate;

	void handleMessage(std::string message) override;
};
#endif