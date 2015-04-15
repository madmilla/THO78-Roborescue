
#pragma once
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <math.h> 
#include <fstream>

class rotate{
public:
	
	/* Rotate a point could 
	 * @param angle the rotation angle in Degrees
	 * @param cloud the cloud to be rotated
	 */ 
	pcl::PointCloud<pcl::PointXY> rotate_point(float angle, pcl::PointCloud<pcl::PointXY> cloud);

	/* Add coordinates from .csv file to PointXY struct
	 * @param cloud the point could to filled with coordinates
	 * @param FStream the filestream with the file containing coordinates
	 */
	pcl::PointCloud<pcl::PointXY> fillClouds(pcl::PointCloud<pcl::PointXY> cloud, std::ifstream& fStream );

	/* Search for duplicate points and remove them from the second point clouds
	 * @param cloud_a the first point could 
	 * @param cloud_b the second point could
	 */ 
	pcl::PointCloud<pcl::PointXY> removeDuplicates(pcl::PointCloud<pcl::PointXY> cloud_a, pcl::PointCloud<pcl::PointXY> cloud_b);
	
	/* Print the could by looping through the coordinates
	 * @param cloud given point cloud 
	 */
	void printCloud(pcl::PointCloud<pcl::PointXY> cloud);
}