#include "mavlink.h"
#include "mavlinkListener.h"
class SomeClass : public MavlinkListener{
	public:
		SomeClass();
		void update(mavlink_message_t* msg) override;
};