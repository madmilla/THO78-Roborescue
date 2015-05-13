#include <iostream>
#include <math.h> 
#include <fstream>
#include "rotate.h"
#include "PointCloud.h"

Pointcloud rotatePoint(float angle, Pointcloud cloud){
	const int halfCircle = 180;
	float sn = sin(angle*M_PI/halfCircle);
	float cs = cos(angle*M_PI/halfCircle); 
	std::vector<Pointcloud::Point> points = cloud.getPoints();

	for (Pointcloud::Point p : points) {    	
		int x = p.X;
		int y = p.Y;
		int nx = x * cs - y * sn; 
		int ny = x * sn + y * cs;
		cloud.removePoint(x, y);
		cloud.setPoint(nx,ny);
		nx = 0;
		ny = 0;
	}
	
	return cloud;
}
