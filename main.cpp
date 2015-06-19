#include "quadcopterwindow.h"
#include "quadcopter.h"
#include "MAVlinkExchanger.h"
#include "SerialPort.h"

int main()
{
	SerialPort p("");
	MAVlinkExchanger e(p);
	Quadcopter q(e);
	QuadCopterWindow w(q);
	w.show();
	return 0;
}