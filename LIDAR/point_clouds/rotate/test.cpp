#include <iostream>
#include <math.h> 
#include <fstream>
#include "rotate.h"
#define RANDOM rand() % 100

int main (int argc, char** argv)
{
	if( argc != 2 ){
		std::cerr << "specify rotation angle\n";
		exit(0);
	}
	float angle = atof(argv[1]);		
	printf("Rotating %f degrees \nOriginal cloud:\n", angle);
	
	Pointcloud cloud;
	for(int i = 0; i < 15; i++){	
		cloud.setPoint(RANDOM, RANDOM);
	}
	cloud.printPoints();
	cloud = rotate_point(angle, cloud);
	printf("Rotated cloud: \n");
	cloud.printPoints();

	return (0);
}
