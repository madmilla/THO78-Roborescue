#include "Quadcopter.h"
#include "ATV.h"
#include "MAVLinkExchanger.h"
#include "DatabaseConnector.h"
#include "MapFactory.h"
#include <iostream>
#include "TCPConnection.h"
#include <boost/asio.hpp>

int main(int argc, char *argv[])
{
    boost::asio::io_service service;
    TCPConnection p{ service };
    MAVLinkExchanger exch{ &p };
    Quadcopter q{ exch };
    ATV a{ exch };
    databaseConnector dbc("127.0.0.1","root","desktop","robodata");
    dbc.setMap(1);
    mapFactory mf{};
    std::cout << mf.loadMapFromDatabase(dbc);
    
    return 1;
}
