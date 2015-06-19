#include "quadcopterwindow.h"
#include "Quadcopter.h"
#include "MAVlinkExchanger.h"
#include "SerialPort.h"

int main()
{
	SerialPort p("");
	MAVLinkExchanger e(p);
	Quadcopter q(e);
	QuadCopterWindow w(q);
	w.show();
	return 0;
}