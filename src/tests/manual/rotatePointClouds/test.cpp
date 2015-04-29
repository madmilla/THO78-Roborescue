#include <iostream>
#include <math.h> 
#include <fstream>
#include "rotate.h"
#include "PointCloud.h"
#define RANDOM rand() % 100

int main (int argc, char** argv)
{
	std::ofstream testLog;
	testLog.open("testlog");
	float angle = 0;
	if( argc != 2 ){
		testLog << "Rotation angle not specified. TEST FAILED!\n";
		std::cerr << "specify rotation angle\n";
		testLog.close();
		exit(0);
	}
	else{
		angle = atof(argv[1]);		
		testLog << "Rotation: " << angle << "\n";
	}
	printf("Rotating %f degrees \nOriginal cloud:\n", angle);
	
	Pointcloud cloud, rotatedCloud;
	for(int i = 0; i < 15; ++i){	
		cloud.setPoint(RANDOM, RANDOM);
	}
	cloud.printPoints();
	rotatedCloud = rotate_point(angle, cloud);
	printf("Rotated cloud: \n");
	rotatedCloud.printPoints();
	
	testLog<< "Rotating cloud 360 degrees to test if rotated cloud matches original\n";
	
	rotatedCloud = rotate_point(360, cloud);
	std::vector<Pointcloud::Point> points1 = cloud.getPoints();
	std::vector<Pointcloud::Point> points2 = rotatedCloud.getPoints();
	
	int i = 0;
	for (Pointcloud::Point p1 : points1) {
		if(!(p1.X == points2.at(i).X) && (p1.Y == points2.at(i).Y)) {
			testLog << "Rotated clouds do not match. TEST FAILED!\n";
			testLog.close();
			exit(0);
		}
		++i;
	}
	testLog << "Cloud succesfully rotated. TEST SUCCESFULL!\n";
	
	testLog.close();
	return (0);
}
