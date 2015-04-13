#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <math.h> 
#include <fstream>


pcl::PointCloud<pcl::PointXY> rotate_point(float angle, pcl::PointCloud<pcl::PointXY> cloud)
{
	
	float sn = sin(angle*M_PI/180);
	float cs = cos(angle*M_PI/180); 
  
	// rotate point
	for (size_t i = 0; i < cloud.size(); ++i) {    	
		float x = cloud.points[i].x;
		float y = cloud.points[i].y;
		float nx = x * cs - y * sn; 
		float ny = x * sn + y * cs;
		cloud.points[i].x = nx;
		cloud.points[i].y = ny;
		nx = 0;
		ny = 0;
	}
	
	// translate point back:
	return cloud;
}


/* Add coordinates from .csv file to PointXY struct
 */
pcl::PointCloud<pcl::PointXY> fillClouds(pcl::PointCloud<pcl::PointXY> cloud, std::ifstream& fStream )
{
	float x, y;
	for (size_t i = 0; i < cloud.size(); ++i)
	{
		fStream >> x;
        fStream >> y;
		cloud.points[i].x = x;
		cloud.points[i].y = y;
	}	
	return cloud;
}

/* Search for duplicate points and remove them from the second point clouds
 */ 
pcl::PointCloud<pcl::PointXY> removeDuplicates(pcl::PointCloud<pcl::PointXY> cloud_a, pcl::PointCloud<pcl::PointXY> cloud_b)
{
	for(size_t i = 0; i < cloud_a.points.size(); ++i) { 
		for(size_t i2 = 0; i2 < cloud_b.points.size(); ++i2) { 
			if((cloud_a.points[i].x == cloud_b.points[i2].x) && (cloud_a.points[i].y == cloud_b.points[i2].y))  { 
				std::cout << "duplicate found \n"; 
				cloud_b.erase(cloud_b.begin() +i2, cloud_b.begin() + (i2+1)); 
			}
		}
	}
	return cloud_b;
}

void printCloud(pcl::PointCloud<pcl::PointXY> cloud){
	for (size_t i = 0; i < cloud.size (); ++i){
		std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << std::endl;
    }
}
