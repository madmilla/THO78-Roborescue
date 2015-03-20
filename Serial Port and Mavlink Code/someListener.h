#include "mavlinkSubject.h"
#include "mavlinkListener.h"
class SomeListener : public MavlinkListener{
	public:
		SomeListener();
		SomeListener(MavlinkSubject * m);
		void update(mavlink_message_t* msg) override;
};