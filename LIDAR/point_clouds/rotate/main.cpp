#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <math.h> 
#include <fstream>
#include "rotate.h"

int main (int argc, char** argv)
{
	if( argc != 3 ){
		std::cerr << "specify cloud and rotation angle\n";
		exit(0);
	}
	std::ifstream fOpen;
			
	fOpen.open(argv[1]);
	float angle = atof(argv[2]);	
    float fOne, fTwo;
    int line1 = 0, line2 = 0;
    std::string temp;
	
	pcl::PointCloud<pcl::PointXY> cloud_a, cloud_b, cloud_c;
	pcl::PointCloud<pcl::Normal> n_cloud_b;
	pcl::PointCloud<pcl::PointNormal> p_n_cloud_c;
	
	/* count number of lines in point cloud file. 
	 * used in for loops later on
	 */
    while(std::getline(fOpen, temp)) { ++line1; }
    /* clean filestreams
	 * return to the beginning of the file
	 */ 
	fOpen.clear();
	fOpen.seekg(0, fOpen.beg);

	/* set cloud width and height
	 */
	cloud_a.width  = line1;
	cloud_a.height = cloud_b.height = n_cloud_b.height = 1;
    cloud_a.points.resize (cloud_a.width * cloud_a.height);


	/* create clouds, remove duplicate coordinates and finally merge.
	 */ 
	cloud_a = fillClouds(cloud_a, fOpen );
	
	std::cerr << "Original: " << std::endl;
	printCloud(cloud_a);
	
	
	printf("Rotating %f degrees \n", angle);
	
	//rotate clouds degrees 
	cloud_b = rotate_point(angle, cloud_a); 
	
	printCloud(cloud_b);
	
	
	fOpen.close();
	return (0);
}
