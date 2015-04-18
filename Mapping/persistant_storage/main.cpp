#include <iostream>
#include "databaseconnector.h"
#include "point.hpp"
#include <vector>

template<typename T>
std::ostream& operator<< ( std::ostream& os, const std::vector<T>& vec ) {
    for ( auto& el : vec ) {
        os << el << std::endl;
    }
    return os;
}


int main() {
    databaseConnector db ( "tcp://127.0.0.1:3306", "root" , "desktop", "roborescue" );
    std::cout<<db.getAllPositions ( 3,true );
    return 0;
}
