#include <stdio.h>
//#include <tchar.h>
#include "serial.h"
#include "ioDevice.h"
#include "someListener.h"
#include "mavlinkSubject.h"
#include <string>
#include <iostream>
#include <cstring>
#include "mavlink/include/common/mavlink.h"
#include <sys/time.h>

double getTimeMillis(){
	struct timeval  tv;
gettimeofday(&tv, NULL);

return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
}

// application reads from the specified serial port and reports the collected data
int main() {
	std::cout << "Welcome to the serial test app!\n\n";
	std::string port = "";
	#if defined(_WIN64) || defined(_WIN32)
	port = "\\\\.\\COM";
	#elif defined(linux)
	port = "/dev/tty";
	#else
	Error OS not defined.
	#endif

	
	std::cout << "Com port to connect to: " << port;
	std::string line = "";
	while (line.compare("") == 0) {
		std::getline(std::cin, line);
	}
	port += line;
	

	char in = ' ';
	while (in != '1' && in != '2') {
		std::cout << "1 for send, 2 for receive.\n";
		std::cin >> in;
	}
	
	MavlinkSubject * m = new MavlinkSubject();
	IoDevice* ioDevice = new Serial(port);
	m->start(ioDevice);
	SomeListener * s = new SomeListener(m);
	if (in == '1') {
		mavlink_ping_t* testArray = new mavlink_ping_t();
		testArray->time_usec = getTimeMillis();
		testArray->seq = 0;
		mavlink_message_t* msg = new mavlink_message_t();
		mavlink_msg_ping_encode(1, 2, msg, testArray);
		m->sendMessage(*msg);
		delete testArray;
		while (m->update()){}
	} else if (in == '2') {
		while (m->update()){}
	}
	return 0;
}
