/**
 * @file Test.cpp
 * @author Coen Andriessen
 * @version 1.2
 */

#include "Test.h"

/**
 * Constructor of Test.
 *
 * @param map
 */

Test::Test(Map * map){
    this->map = map;
    myfile.open("C:\\Users\\coen__000\\Documents\\TestSystem\\testresults.txt", std::ios::out|std::ios::app);
    writeTimeAndDate();
}

/**
 * Destructor of scanArea.
 */

Test::~Test(){

}

/**
 * Function to run tests before the scanning algorithm is started.
 */

void Test::testsBeforeScanning(){
    writeMap();
    start = std::clock();
}

/**
 * Function to run tests when the scanning algorithm is done.
 */

void Test::testsAfterScanning(){
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    checkFullyScanned();
    writeMap();
    writeNumberOfSteps();
    writeExecuteTime();
    writeEndLine();
}

/**
 * Function to write the time and date in the output file.
 */

void Test::writeTimeAndDate(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    myfile << "Date: " << (now->tm_mday) << "-" << (now->tm_mon +1) << "-" << (now->tm_year + 1900);
    myfile << " Time: " << (now->tm_hour) << ":" << (now->tm_min) << ":" << (now->tm_sec) << "\n";
}

/**
 * Function to write if the map is full scanned in the output file.
 */

void Test::checkFullyScanned(){
    if(map->isMapFullScanned()){
        myfile << "Map is succesfull scanned\n";
    }else{
        myfile << "Map scanned is failed";
    }
}

/**
 * Function to write the loaded or scanned map in the output file.
 */

void Test::writeMap(){
    myfile << "Scanned map:\n";
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            myfile << map->getTile(iix, iiy);
            if(iix == 19){
                myfile << "\n";
            }
        }
    }
    myfile << "\n";
}

/**
 * Write number of steps the rosbee has taken in the output file.
 */

void Test::writeNumberOfSteps(){
    myfile << "Number of steps: " << map->getNumberOfSteps() << "\n";
}

/**
 * Write end line of the test.
 */

void Test::writeEndLine(){
    for(int i = 0; i < 150; i++){
        myfile << "=";
    }
    myfile << "\n";
}

/**
 * Write run time of algorithm in the output file.
 */

void Test::writeExecuteTime(){
    myfile << "Time: " << duration << "\n";
}
