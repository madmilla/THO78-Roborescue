#ifndef TEST_H
#define TEST_H

#include <map.hpp>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

class Test
{
public:
    // Constructor of test.
    Test(map * Map);
    // Destructor of test.
    ~Test();
    // Function to check and write if the map is full scanned.
    void checkFullyScanned();
    // Function to write the time and date in the output file.
    void writeTimeAndDate();
    // Function to write the loaded and scanned map in the output file.
    void writeMap();
    // Function to start tests that will be runned before the scanning algorithm.
    void testsBeforeScanning();
    // Function to start tests that will be runned after the scanning algorithm.
    void testsAfterScanning();
    // Function to write number of steps what the rosbee has taken by the scanning algorithm.
    void writeNumberOfSteps();
    // Function to write the end line of the tests in the output file.
    void writeEndLine();
    // Function to write the run time of the scanning algorithm in the output file.
    void writeExecuteTime();
private:
    map * Map;
    std::ofstream myfile;
    std::clock_t start;
    double duration;
};

#endif // TEST_H
