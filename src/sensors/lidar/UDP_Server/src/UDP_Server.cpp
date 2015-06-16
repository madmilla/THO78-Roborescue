#include <iostream>
#include <stdlib.h>
#include <thread>

#include "PracticalSocket.h"
#include "mavlink/udp_mavlink_commands/mavlink.h"

using namespace std;

mavlink_message_t encodeRalcpMessage(uint64_t payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf);
mavlink_ralcp_t decodeRalcpMessage(mavlink_message_t & mavlinkMessage);


//Na 30 seconden timed the socket out en zal er een socketTimeoutExeption worden aangeroepen.
//Als je dit wilt aanpassen moet je dat veranderen in de prackticalsocket.cpp in de functie recvFRom
int main()
{
    UDPSocket sock;
    //Verander IP
    SocketAddress localadr("145.89.158.190", 8888, SocketAddress::UDP_SOCKET);
    sock.bind(localadr);
    SocketAddress remoteadr;
    cout << "UDP Server is gestart:" << endl;

    //Dit bericht wordt verstuurd
    mavlink_message_t msg = encodeRalcpMessage(uint64_t(0), COMMAND_DESTINATION::COMMAND_DESTINATION_ENUM_END, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);

    while(true){
            try{
				sock.recvFrom(&msg, sizeof(mavlink_ralcp_t), remoteadr);

				cout << "recieved: " << decodeRalcpMessage(msg).Payload << endl;

				//Opnieuw een bericht samen stellen
				msg = encodeRalcpMessage( uint64_t(decodeRalcpMessage(msg).Payload+1), COMMAND_DESTINATION::COMMAND_DESTINATION_ENUM_END, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);

				sock.sendTo(&msg, sizeof(mavlink_ralcp_t), remoteadr);

				cout << "sending: " << decodeRalcpMessage(msg).Payload << endl;
				cout << "from: " << remoteadr.getAddress() << ":" << remoteadr.getPort() << endl;

				sleep(1);
            }catch(SocketTimedOutException e){
            	continue;
            }
    }
}

mavlink_message_t encodeRalcpMessage(uint64_t payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){
	mavlink_message_t mavlinkMessage;
	mavlink_ralcp_t mavlinkRALCP{payload, dest, lcf};
	mavlink_msg_ralcp_encode(1, COMMAND_DESTINATION::LIDAR, &mavlinkMessage, &mavlinkRALCP);

	return mavlinkMessage;
}

mavlink_ralcp_t decodeRalcpMessage(mavlink_message_t & mavlinkMessage){
	mavlink_ralcp_t mavlinkRALCP;
	mavlink_msg_ralcp_decode(&mavlinkMessage, &mavlinkRALCP);

	return mavlinkRALCP;
}
