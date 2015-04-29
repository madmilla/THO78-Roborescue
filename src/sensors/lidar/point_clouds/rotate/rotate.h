/*!
 * \brief Class with the function to rotate a point cloud.
 * \details The rotate class has the function to rotate a point cloud with a given angle.
 * \author Owen Hoogenboezem - 1643103
 * \author Arnout Reitsma - 1646715
 * \version 1.2
 * \date 15-04-2015
 */

#ifndef ROTATE_H  
#define ROTATE_H
   
#include <iostream>
#include <math.h> 
#include <fstream>
#include "PointCloud.h"

/*! Rotate a point could 
 * @param angle the rotation angle in Degrees
 * @param cloud the cloud to be rotated
 */ 
Pointcloud rotatePoint(float angle, Pointcloud cloud);

#endif
