#include <stdio.h>
//#include <tchar.h>
#include "serial.h"
#include "ioDevice.h"
#include "someListener.h"
#include "mavlinkSubject.h"
#include <string>
#include <iostream>
#include <cstring>
#include "mavlink/include/telemetryTest/mavlink.h"

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
	m->start(port);
	SomeListener * s = new SomeListener(m);
	if (in == '1') {
		while (1) {
			std::cout << "Message to send:";
			std::string line;
			std::getline(std::cin, line);
			if (line.compare("") == 0) {
				continue;
			}

			mavlink_message_t* msg = new mavlink_message_t();
			mavlink_array_test_0_t* array = new mavlink_array_test_0_t();

			char msgText[32];
			std::fill(msgText,msgText+32,' ');
			std::strcpy(msgText, line.c_str());
			
			mavlink_msg_array_test_0_pack(1, 2, msg, 50, msgText);
			m->sendMessage(*msg);

			std::cout << "Data sent with telemetry\n";
		}
	} else if (in == '2') {
		while (m->update()){}
		/* while (SP->isConnected()) {

			mavlink_message_t receiveMessage;
			mavlink_status_t status;

			if (SP->getBufferSize() < 1){
				continue;
			}

			char c;
			SP->readData(&c,1);
			// Try to get a new message
			if (mavlink_parse_char(MAVLINK_COMM_0, c, &receiveMessage,
					&status)) {
				std::cout << "Message parsed\n";
				// Handle message

				switch (receiveMessage.msgid) {
				case MAVLINK_MSG_ID_HEARTBEAT: {
					// E.g. read GCS heartbeat and go into
					// comm lost mode if timer times out
				}
					break;
				case MAVLINK_MSG_ID_ARRAY_TEST_0:
				{
					std::cout
							<< "Test message received. Message content: [";
					mavlink_array_test_0_t* testArray =
							new mavlink_array_test_0_t();
					mavlink_msg_array_test_0_decode(&receiveMessage,
							testArray);
					for (int i = 0; i < 32; i++) {
						std::cout << testArray->ar_c[i];
					}
					std::cout << "]\n";
					delete testArray;
					break;
				}
				default:
					std::cout
							<< "default message triggered, add extra cases to catch all msgid's.\n";
					break;
				}
			}
		} */
	}
	return 0;
}
