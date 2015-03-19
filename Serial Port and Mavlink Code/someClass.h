#include "mavlinkSubject.h"
#include "mavlinkListener.h"
class SomeClass : public MavlinkListener{
	public:
		SomeClass();
		SomeClass(MavlinkSubject * m);
		void update(mavlink_message_t* msg) override;
};