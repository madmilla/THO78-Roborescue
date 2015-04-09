#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>


pcl::PointCloud<pcl::PointXY> rotate_point(float cx,float cy,float angle, pcl::PointCloud<pcl::PointXY> cloud)
{
  float s = sin(angle);
  float c = cos(angle);
  // translate point back to origin:

  // rotate point

  float x = cloud.points[0].x;
  float y = cloud.points[0].y;

  float nx = cos(angle) * (x-cx) - sin(angle) * (y-cy) + cx;
  float ny = sin(angle) * (nx-cx) + cos(angle) * (y-cy) + cy;




  // translate point back:
  cloud.points[0].x = nx;
  cloud.points[0].y = ny;
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

int main (int argc, char** argv)
{
	if( argc != 2 ){
		std::cerr << "specify cloud\n";
		exit(0);
	}
	std::ofstream fOut;
	std::ifstream iOne, iTwo;
			
	iOne.open(argv[1]);
		
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


	/* create clouds, remove duplicate coordinates and finally merge.
	 */ 
	cloud_a = fillClouds(cloud_a, iOne );
	
	std::cerr << "Cloud A: " << std::endl;
	printCloud(cloud_a);
	
	
	std::cerr << "Rotated " << std::endl;
	cloud_b = rotate_point(0, 0, 180, cloud_a); 
	
	printCloud(cloud_b);
	fOut.close();
	iOne.close();
	iTwo.close();
	return (0);
}
