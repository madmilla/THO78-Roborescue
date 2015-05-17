#include "communication/persistant_storage/databaseconnector.h"
#include "communication/persistant_storage/point.hpp"
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<< ( std::ostream& os, const std::vector<T>& vec ) {
    for ( auto& el : vec ) {
        os << el << std::endl;
    }
    return os;
}


int main(int argc, char* argv[]) {
    if(argc < 3){
        std::cout << "no password specified\nUsage: " << argv[0] <<" [username] [password]\n";
        return 0;
    }
    std::string username = argv[1];
    std::string password = argv[2];
std::cout<<username<<"  "<<password<<"\n";
   // databaseConnector db ( "tcp://127.0.0.1:3306", username , password, "roborescue" );
//	db.getPolygons();
    return 0;
}
