#include "communication/persistant_storage/databaseconnector.h"
#include "communication/persistant_storage/point.hpp"
#include <iostream>
#include <vector>
#include <chrono>

#define times 100000

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
    databaseConnector db ( "tcp://127.0.0.1:3306", username , password, "robodata" );
    db.setMap(1);

    point p1(2800, 3000);
    point p2(4400, 3000);
    point p3(4400, 4000);
    point p4(2800, 4000);

    std::vector<point> polygon{p1,p2,p3,p4,p1};

    std::cout<<"starting "<<times<<" time isAccessable with a point\n";
    auto start = std::chrono::high_resolution_clock::now();
   for(int i=0;i<times;i++){
        db.isAccessable(p1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<"done\n";
    auto durNs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    auto durMs = std::chrono::duration_cast<std::chrono::milliseconds>(durNs);
    auto durPerCountNs = std::chrono::duration_cast<std::chrono::nanoseconds>(durNs/times);
    auto durPerCountMs = std::chrono::duration_cast<std::chrono::milliseconds>(durPerCountNs);
    std::cout << "Measured time          : " << durNs.count() << " ns\n";
    std::cout << "Measured time          : " << durMs.count() << " ms\n";
    std::cout << "Measured time per count: " << durPerCountNs.count() << " ns\n";
    std::cout << "                       : " << durPerCountMs.count() << " ms\n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";



    std::cout<<"starting "<<times<<" time isAccessable with a polygon\n";
    start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<times;i++){
        db.isAccessable(polygon);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout<<"done\n";
    durNs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    durMs = std::chrono::duration_cast<std::chrono::milliseconds>(durNs);
    durPerCountNs = std::chrono::duration_cast<std::chrono::nanoseconds>(durNs/times);
    durPerCountMs = std::chrono::duration_cast<std::chrono::milliseconds>(durPerCountNs);
    std::cout << "Measured time          : " << durNs.count() << " ns\n";
    std::cout << "Measured time          : " << durMs.count() << " ms\n";
    std::cout << "Measured time per count: " << durPerCountNs.count() << " ns\n";
    std::cout << "                       : " << durPerCountMs.count() << " ms\n";    
    return 0;

}
