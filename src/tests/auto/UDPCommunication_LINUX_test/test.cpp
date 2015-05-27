

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include <thread>

#include "../../../sensors/lidar/UdpClient/PracticalSocket.h"
#include "../../../sensors/lidar/UdpClient/UDPClient.h"
#include "../../../sensors/lidar/UdpClient/CPIConnector.h"
#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"

using namespace std;

int main(int argc, char **argv)
{


    std::stringstream filename;
    time_t t = time(0);   // get time now
    struct tm * now = localtime(&t);
    filename << "UDPservertest_LINUX - " << now->tm_year + 1900 << "-" << now->tm_mon + 1 << "-" << now->tm_mday << ".txt";
    std::ofstream output(filename.str());

    UDPSocket sock;
    SocketAddress localadr("127.8.0.1", 8080, SocketAddress::UDP_SOCKET);
    sock.bind(localadr);
    SocketAddress remoteadr;

    UDPClient sock2;
    CPIConnector cp{1};
    sock2.addListener(&cp);

    mavlink_ralcp_t msg{0, COMMAND_DESTINATION::COMMAND_DESTINATION_ENUM_END, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT};
    int count = 0;
    while(true){
            try{

                    sock.recvFrom(&msg, sizeof(mavlink_ralcp_t), remoteadr);

                    cout << "recieved: " << msg.Payload << endl;

                    if (count > 8){
                        cout << "Test was succesfull" << count <<  endl;
                        output << "Test was succesfull" << count << endl;
                        break;
                    }


                    msg = mavlink_ralcp_t{count, msg.Destination+1, msg.Function+1};

                    sock.sendTo(&msg, sizeof(mavlink_ralcp_t), remoteadr);

                    cout << "sending: " << msg.Payload << endl;
                    cout << "from: " << remoteadr.getAddress() << ":" << remoteadr.getPort() << endl;
                    count++;

                    sleep(2);
            }catch(SocketTimedOutException e){continue;}
    }

    output.close();
}
