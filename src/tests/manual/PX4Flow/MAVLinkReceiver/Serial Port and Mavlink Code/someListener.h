#include "mavlinkSubject.h"
#include "mavlinkListener.h"
#include <fstream>
#include "PX4FlowWrapper.h"

class SomeListener : public MavlinkListener{
	public:
		SomeListener();
		SomeListener(MavlinkSubject * m);
		void update(mavlink_message_t* msg) override;
	private:
		MavlinkSubject* m;
		PX4FlowWrapper* pX4FlowWrapper = new PX4FlowWrapper();
		char img = 0;
		std::fstream imgFile;
		int size = 0;
};