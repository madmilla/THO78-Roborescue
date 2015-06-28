#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "lpc_com.h"
 
using namespace std;
 
int main (void) {
	double battery = 0, temperature = 0;
	
	LPCCom port("/dev/ttyAMA0", "4");
	port.init();
	port.readData(battery, temperature);

	cout << "Battery: " << battery << " Temperature: " << temperature << endl;

    cout << "Exiting....." << endl;
    return 0;
}
