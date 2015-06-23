#ifndef _VictimLocalisationModule_H
#define _VictimLocalisationModule_H
#include "TCPClient.h"

class VictimLocalisationModule : public TCPClient
{
public:
	VictimLocalisationModule(io_service& service, std::string host, std::string port);

	/**
	* \brief Get the id of the victim tag
	*
	* Get the id of the most recently found victim tag
	*
	* \return id of the most recently found victim tag
	*/
	int getVictimId() const;

	/**
	* \brief Get if a victim has been found
	*
	* Get the if a victim has been found
	*
	* \return bool if a victim has been found
	*/
	bool isVictimFound() const;

private:
	bool victimFound;
	int victimId;

	void handleMessage(std::string message) override;
};
#endif