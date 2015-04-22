#include <iostream>
#include <math.h> 
#include <fstream>
#include "rotate.h"
#include "PointCloud.h"

Pointcloud rotate_point(float angle, Pointcloud cloud){
	
	float sn = sin(angle*M_PI/180);
	float cs = cos(angle*M_PI/180); 
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
