#ifndef MAPLOGICVSLAM_H
#define MAPLOGICVSLAM_H

#include <map.hpp>
#include <Rosbee.h>
#include <Lidar.h>

class mapLogicVSLAM
{
public:
	mapLogicVSLAM(map * Map, Rosbee * rosbee, Lidar * lidar);
	~mapLogicVSLAM();
	void setTilesInRangeLidar();
	int * getUnscannedTile();
	bool isMapFullyScanned();
	map * Map;
	Rosbee * rosbee;
	Lidar * lidar;
};

#endif // MAPLOGICVSLAM_H
