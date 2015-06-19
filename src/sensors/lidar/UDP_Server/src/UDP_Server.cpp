#include <iostream>
#include <stdlib.h>
#include <thread>

#include "PracticalSocket.h"
#include "mavlink/udp_mavlink_commands/mavlink.h"

using namespace std;

//The function decodeRalcpMessage decodes an mavlink_message_t to an mavlink_ralcp_t
mavlink_rosbee_message_t decodeRosbeeMessage(mavlink_message_t & mavlinkMessage){
	mavlink_rosbee_message_t mavlinkRALCP;
	mavlink_msg_rosbee_message_decode(&mavlinkMessage, &mavlinkRALCP);

	return mavlinkRALCP;
}

mavlink_lidar_message_t decodeLidarMessage(mavlink_message_t & mavlinkMessage){
	mavlink_lidar_message_t mavlinkRALCP;
	mavlink_msg_lidar_message_decode(&mavlinkMessage, &mavlinkRALCP);

	return mavlinkRALCP;
}

//The function encodeRalcpMessage encodes an mavlink_ralcp_t to an mavlink_message_t
mavlink_message_t encodeRosbeeMessage(uint64_t payload, COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS lcf){
	mavlink_message_t mavlinkMessage;
	mavlink_rosbee_message_t mavlinkRALCP{payload, dest, lcf};
	mavlink_msg_rosbee_message_encode(1, COMMAND_DESTINATION::ROSBEE, &mavlinkMessage, &mavlinkRALCP);

	return mavlinkMessage;
}

mavlink_message_t encodeLidarMessage(int32_t * payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){

	mavlink_message_t mavlinkMessage;
	mavlink_lidar_message_t mavlinkRALCP;
	for(int i=0; i< 6; i++){
		mavlinkRALCP.Payload[i] = payload[i];
	}

	mavlinkRALCP.Destination = dest;
	mavlinkRALCP.Function = lcf;
	mavlink_msg_lidar_message_encode(1, COMMAND_DESTINATION::LIDAR, &mavlinkMessage, &mavlinkRALCP);

	return mavlinkMessage;
}

//Na 30 seconden timed the socket out en zal er een socketTimeoutExeption worden aangeroepen.
//Als je dit wilt aanpassen moet je dat veranderen in de prackticalsocket.cpp in de functie recvFRom
int main()
{
    UDPSocket sock;
    //Verander IP
    SocketAddress localadr("172.16.120.134", 8888, SocketAddress::UDP_SOCKET);
    sock.bind(localadr);
    SocketAddress remoteadr;
    cout << "UDP Server is gestart:" << endl;

    int32_t temp[5]= {1,2,3,4,5};
    //Dit bericht wordt verstuurd
    mavlink_message_t msg = encodeLidarMessage(temp, COMMAND_DESTINATION::COMMAND_DESTINATION_ENUM_END, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);

    while(true){
            try{
				sock.recvFrom(&msg, sizeof(mavlink_message_t), remoteadr);

				cout << "recieved: " << decodeLidarMessage(msg).Payload[0] << endl;

				//Opnieuw een bericht samen stellen
				for(int i=0; i< 6; i++){
					temp[i] = decodeLidarMessage(msg).Payload[i] + 1;
				}

				msg = encodeLidarMessage( temp, COMMAND_DESTINATION::COMMAND_DESTINATION_ENUM_END, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);

				sock.sendTo(&msg, sizeof(mavlink_message_t), remoteadr);

				cout << "sending: " << decodeLidarMessage(msg).Payload[0] << endl;
				cout << "from: " << remoteadr.getAddress() << ":" << remoteadr.getPort() << endl;

				sleep(1);
            }catch(SocketTimedOutException e){
            	continue;
            }
    }
}

