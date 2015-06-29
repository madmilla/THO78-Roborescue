#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "lpc_com.h"
 
using namespace std;
 
int main (void) {
	double temperature = 0;
	
	LPCCom port("/dev/ttyAMA0", "4");
	port.init();
	temperature = port.readData();

	cout << "Temperature: " << temperature << endl;

    cout << "Exiting....." << endl;
    return 0;
}
