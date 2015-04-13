#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>
#include "combine.h"

int main (int argc, char** argv)
{
	if( argc != 4 ){
		std::cerr << "specify cloudA, cloudB and output file\n";
		exit(0);
	}
	std::ofstream fOut;
	std::ifstream iOne, iTwo;
	fOut.open(argv[3]);		
	iOne.open(argv[1]);
	iTwo.open(argv[2]);			
    float fOne, fTwo;
    int line1 = 0, line2 = 0;
    std::string temp;
	
	pcl::PointCloud<pcl::PointXY> cloud_a, cloud_b, cloud_c;
	pcl::PointCloud<pcl::Normal> n_cloud_b;
	pcl::PointCloud<pcl::PointNormal> p_n_cloud_c;
	
	/* count number of lines in point cloud file. 
	 * used in for loops later on
	 */
    while(std::getline(iOne, temp)) { ++line1; }
    
    while(std::getline(iTwo, temp)) { ++line2; }
	/* clean filestreams
	 * return to the beginning of the file
	 */ 
	iOne.clear();
	iOne.seekg(0, iOne.beg);
	iTwo.clear();
	iTwo.seekg(0, iTwo.beg);
	

	/* set cloud width and height
	 */
	cloud_a.width  = line1;
	cloud_a.height = cloud_b.height = n_cloud_b.height = 1;
    cloud_a.points.resize (cloud_a.width * cloud_a.height);

	cloud_b.width  = line2;
	cloud_b.points.resize (cloud_b.width * cloud_b.height);	
	/* create clouds, remove duplicate coordinates and finally merge.
	 */ 
	cloud_a = fillClouds(cloud_a, iOne );
	cloud_b = fillClouds(cloud_b, iTwo );
	std::cerr << "Cloud A: " << std::endl;
	printCloud(cloud_a);
	std::cerr << "Cloud B: " << std::endl;
	printCloud(cloud_b);
	
	cloud_c  = cloud_a;
	cloud_b = removeDuplicates(cloud_a, cloud_b); 
	cloud_c += cloud_b;
	
	std::cerr << "Cloud C: " << std::endl;
	printCloud(cloud_c);
	
	for (size_t i = 0; i < cloud_c.points.size (); ++i){
		fOut << "    " << cloud_c.points[i].x << " " << cloud_c.points[i].y << " " << std::endl;
	}
	fOut.close();
	iOne.close();
	iTwo.close();
	return (0);
}
