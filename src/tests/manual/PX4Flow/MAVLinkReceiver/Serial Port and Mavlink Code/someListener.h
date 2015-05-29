#include "mavlinkSubject.h"
#include "mavlinkListener.h"
#include <fstream>
class SomeListener : public MavlinkListener{
	public:
		SomeListener();
		SomeListener(MavlinkSubject * m);
		void update(mavlink_message_t* msg) override;
	private:
		MavlinkSubject* m;
		char img = 0;
		std::fstream imgFile;
		int size = 0;
};