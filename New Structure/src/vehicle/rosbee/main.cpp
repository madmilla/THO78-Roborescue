#include "ros_control.cpp"   

int main(){
	rosbee_driver ross("/dev/ttyUSB0"); //ttyUSB0 refers to the first usb device attached
	
	ross.forward(10);
	sleep(5);
	
	ross.rotate(180);
	sleep(10);

	ross.stop();
	sleep(10);



	/* 
	 * A delay between actions is required because of the limitations of the rosbee software
	 * When the rosbee unit receives a command, it will be bushy processing. This can take
	 * several seconds. If any other command is send during this time it will be ignored.
	 */
}



