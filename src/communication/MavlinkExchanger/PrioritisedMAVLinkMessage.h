#ifndef _PRIORITESMAVLINKMESSAGE_H
#define _PRIORITESMAVLINKMESSAGE_H
#include "ardupilotmega/mavlink.h"
#include <array>
#include <chrono>

const std::array<uint8_t, 1> MEDIUM_PRIORITIES = { MAVLINK_MSG_ID_HEARTBEAT };
const std::array<uint8_t, 1> HIGH_PRIORITIES = { MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE };
const std::array<uint8_t, 0> EXTREME_PRIORITIES = {};

class PrioritisedMAVLinkMessage : public mavlink_message_t
{
public:
	explicit PrioritisedMAVLinkMessage(const mavlink_message_t& baseMessage);
	PrioritisedMAVLinkMessage();

	friend bool operator<(const PrioritisedMAVLinkMessage& lhs, const PrioritisedMAVLinkMessage& rhs);

	enum class Priority
	{
		LOW_PRIORITY,
		MEDIUM_PRIORITY,
		HIGH_PRIORITY,
		EXTREME_PRIORITY
	};
	Priority getPriority() const;
	friend std::ostream& operator<<(std::ostream& stream, const Priority& priority);
private:
	std::chrono::system_clock::time_point timeCreated;
};
#endif