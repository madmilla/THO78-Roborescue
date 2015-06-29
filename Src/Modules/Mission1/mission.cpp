#include "Quadcopter.h"
#include "ATV.h"
#include "MAVLinkExchanger.h"
#include <iostream>
#include "TCPConnection.h"
#include <boost/asio.hpp>

int main(int argc, char *argv[])
{
	boost::asio::io_service service;
    TCPConnection p{ service };
    MAVLinkExchanger exch{ p };
    Quadcopter q{ exch };
    ATV a{ exch };
	return 1;
}