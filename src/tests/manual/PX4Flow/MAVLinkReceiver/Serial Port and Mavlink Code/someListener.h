#include "mavlinkSubject.h"
#include "mavlinkListener.h"
#include "PX4FlowWrapper.h"

class SomeListener : public MavlinkListener{
	public:
		SomeListener();
		SomeListener(MavlinkSubject * m);
		void update(mavlink_message_t* msg) override;
	private:
		MavlinkSubject* m;
		PX4FlowWrapper* pX4FlowWrapper = new PX4FlowWrapper();
};