#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <fstream>

int main (int argc, char** argv)
{
	
	std::ofstream fOut;
	std::ifstream iOne, iTwo;
	fOut.open("output.txt");		
	iOne.open("cloud1.csv");
	iTwo.open("cloud2.csv");			
    float fOne, fTwo;
    float x,y, x2, y2;
    int line1, line2;
    std::string temp;

    while(std::getline(iOne, temp)) { line1++; }
    while(std::getline(iTwo, temp)) { line2++; }
	// return to the beginning of the file
	iOne.clear();
	iOne.seekg(0, iOne.beg);
	iTwo.clear();
	iTwo.seekg(0, iTwo.beg);
	/*
	if (argc != 2)
	{
		std::cerr << "please specify command line arg '-h' or '-v'" << std::endl;
		exit(0);
	}*/
	pcl::PointCloud<pcl::PointXY> cloud_a, cloud_b, cloud_c;
	pcl::PointCloud<pcl::Normal> n_cloud_b;
	pcl::PointCloud<pcl::PointNormal> p_n_cloud_c;

	// Fill in the cloud data
	cloud_a.width  = line1;
	cloud_a.height = cloud_b.height = n_cloud_b.height = 1;
    cloud_a.points.resize (cloud_a.width * cloud_a.height);

	cloud_b.width  = line2;
	cloud_b.points.resize (cloud_b.width * cloud_b.height);
	
	std::cerr << "Size of A: " << cloud_a.points.size() << "\n";
	std::cerr << "Line 1: " << line1 << "\n";
	std::cerr << "Line 2: " << line2 << "\n";
	std::cerr << "Size of B: " << cloud_b.points.size() << "\n";

	for (size_t i = 0; i < cloud_a.points.size (); ++i)
	{
		iOne >> x;
        iOne >> y;
		cloud_a.points[i].x = x;
		cloud_a.points[i].y = y;
	}	
	for (size_t i = 0; i < cloud_b.points.size (); ++i)
	{
		iTwo >> x2;
		iTwo >> y2;
		cloud_b.points[i].x = x2;
		cloud_b.points[i].y = y2;
	}

	std::cerr << "Cloud A: " << std::endl;
	for (size_t i = 0; i < cloud_a.points.size (); ++i)
		std::cerr << "    " << cloud_a.points[i].x << " " << cloud_a.points[i].y << " "  << std::endl;

	std::cerr << "Cloud B: " << std::endl;
	for (size_t i = 0; i < cloud_b.points.size (); ++i)
		std::cerr << "    " << cloud_b.points[i].x << " " << cloud_b.points[i].y << " "  << std::endl;

	// Copy the point cloud data

	cloud_c  = cloud_a;
	
	for(size_t i = 0; i < cloud_a.points.size(); ++i) { 
		for(size_t i2 = 0; i2 < cloud_b.points.size(); ++i2) { 
			if((cloud_a.points[i].x == cloud_b.points[i2].x) && (cloud_a.points[i].y == cloud_b.points[i2].y))  { std::cout << "duplicate found \n"; cloud_b.erase(cloud_b.begin() +i2, cloud_b.begin() + (i2+1)); }//cloud_c.erase(cloud_b.begin()+1); 
		}
	}
	
	cloud_c += cloud_b;
	
	std::cerr << "Cloud C: " << std::endl;
	for (size_t i = 0; i < cloud_c.points.size (); ++i){
		std::cerr << "    " << cloud_c.points[i].x << " " << cloud_c.points[i].y << " " << std::endl;
    }
	for (size_t i = 0; i < cloud_c.points.size (); ++i){
		fOut << "    " << cloud_c.points[i].x << " " << cloud_c.points[i].y << " " << std::endl;
	}
	for (size_t i = 0; i < p_n_cloud_c.points.size (); ++i){
		fOut << p_n_cloud_c.points[i].x << " " << p_n_cloud_c.points[i].y << " " <<  p_n_cloud_c.points[i].normal[0] << " " << p_n_cloud_c.points[i].normal[1]  << std::endl;
	}
	fOut.close();
	return (0);
}
