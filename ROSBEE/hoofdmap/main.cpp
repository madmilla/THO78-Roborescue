

/////////////////////////////////////////////////
// Serial port interface program               //
/////////////////////////////////////////////////

#include <stdio.h> // standard input / output functions
#include <string.h> // string function definitions
#include <unistd.h> // UNIX standard function definitions
#include <fcntl.h> // File control definitions
#include <errno.h> // Error number definitions
#include <termios.h> // POSIX terminal control definitionss
#include <time.h>   // time calls
#include <iostream>



void drive_forward(int speed){
    //open_port();
	
	//send_command("$1,"+speed);

}

void rotate(int degrees){

	//send_command("$2,"+degrees);

}


void send_command(std::string command, std::string port){
	
	int fd; // file description for the serial port
	
	//fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
	fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
	
	if(fd == -1) // if open is unsucessful
	{
		//perror("open_port: Unable to open /dev/ttyS0 - ");
		printf("open_port: Unable to open \n");
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
		printf("port is open.\n");
	}
	
	
	struct termios port_settings;      // structure to store the port settings in

	cfsetispeed(&port_settings, B115200);    // set baud rates
	cfsetospeed(&port_settings, B115200);

	port_settings.c_cflag &= ~PARENB;    // set no parity, stop bits, data bits
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;
	
	tcsetattr(fd, TCSANOW, &port_settings);    // apply the settings to the port
	
	
	char n;
	fd_set rdfs;
	struct timeval timeout;
	
	// initialise the timeout structure
	timeout.tv_sec = 4; // ten second timeout
	timeout.tv_usec = 0;
	
	//Create byte array
	//unsigned char send_bytes[] = { 0x02, 0xFA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x23, 0x01, 0x21, 0x03};
	//unsigned char send_bytes[] = "$1,10";
	char send_bytes[command.size()];
	strcpy(send_bytes, command.c_str());
	
	//command.copy(send_bytes, command.size(), command.size()-1);
	
	//= reinterpret_cast<unsigned char[]*>(command);
	
	write(fd, send_bytes, 6);  //Send data
	printf("Command send. Now we wait \n");
	std::cout << command;
	
	// do the select
	n = select(fd + 1, &rdfs, NULL, NULL, &timeout);
	
	// check if an error has occured
	if(n < 0)
	{
	 perror("select failed\n");
	}
	else if (n == 0)
	{
	 puts("Timeout!");
	 unsigned char send_bytes[] = "$999";
	
	 write(fd, send_bytes, 5);  //Send data
	 printf("Confirmation send. \n");
	 
	}
	else
	{
	 printf("\nBytes detected on the port!\n");
	}
	
}



int main(){


	send_command("$1,10", "/dev/ttyUSB0");

}
