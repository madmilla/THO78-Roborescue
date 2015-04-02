#include <stdio.h>
//#include <tchar.h>
#include "serial.h"
#include "ioDevice.h"
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
	if (in == '1') {
	mavlink_message_t msg = mavlink_message_t();
	//mavlink_msg_command_long_pack(255, 0, &msg, 1, 250, 400, 0, 1, 0, 0, 0, 0, 0, 0);‏Sleep(2000);
	mavlink_msg_command_long_pack(255,0,&msg,1,250,400,0,1,0,0,0,0,0,0);Sleep(2000);
	m->sendMessage(msg);
		Sleep(3000);
		//mavlink_msg_rc_channels_override_pack(1, 0, msg,1,1 1000,UINT16_MAX,UINT16_MAX,UINT16_MAX,UINT16_MAX,UINT16_MAX,UINT16_MAX,UINT16_MAX);
		mavlink_msg_rc_channels_override_pack(255,200,& msg,1,250,1460,UINT16_MAX, 1525, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
		int x = 1;
		while(x){
			m->sendMessage(msg);
			Sleep(1000);
			x--;
		}
		mavlink_msg_rc_channels_override_pack(255,200,& msg,1,250,1887,UINT16_MAX, 1525, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
		
		x = 1;
		while(x){
			m->sendMessage(msg);
			Sleep(1000);
			x--;
		}
		x = 1;
		mavlink_msg_rc_channels_override_pack(255,200,& msg,1,250,1087,UINT16_MAX, 1525, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
		while(x){
			m->sendMessage(msg);
			Sleep(1000);
			x--;
		}
		mavlink_msg_rc_channels_override_pack(255,200,& msg,1,250,UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
		while (m->update()){}
	} else if (in == '2') {
		while (m->update()){}
	}
	return 0;
}
