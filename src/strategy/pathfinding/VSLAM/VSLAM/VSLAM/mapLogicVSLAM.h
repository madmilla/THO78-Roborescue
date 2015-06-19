#ifndef MAPLOGICVSLAM_H
#define MAPLOGICVSLAM_H

#include <map.hpp>
#include <Rosbee.h>

class mapLogicVSLAM
{
public:
	mapLogicVSLAM(map * Map, Rosbee * rosbee);
	~mapLogicVSLAM();
	void setTilesInRangeLidar();
	int * getUnscannedTile();
	map * Map;
	Rosbee * rosbee;
};

#endif // MAPLOGICVSLAM_H
