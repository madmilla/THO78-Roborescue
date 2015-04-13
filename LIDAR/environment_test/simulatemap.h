#ifndef SIMULATEMAP_H
#define SIMULATEMAP_H
#include "map.h"
#include "PointCloud.h"

//! The Simulate class
/*!
The object which will contain all simulation data
*/
class SimulateMap
{
private:
    int lidarX = 0; //Coordinates of the lidar
    int lidarY = 0; //coordinates of the lidar
    Map *map; //Pointer to the map
public:
    //! The simulateMap constructor for an existing map
    /*!
    Create a simulateMap object from an existing map
    @param map: the vector containing the map
    */
    SimulateMap(Map *map);
    //! Perform a simulation on the given map
    /*!
    Detect all objects around the lidar and return a pointcloud containt the coordinates
    @return Pointcloud this is a struct containing the x and y coordinates of the found object
    */
    Pointcloud simulate();
    //! Set the scanpoint(the point where the lidar is located)
    /*!
    Set the scanpoint of the Lidar
    */
    void setScanPoint(int y, int x);
    //! Default destructor of simulate map
    /*!
      The default destructor of simulate map
    */
    ~SimulateMap();
};

#endif // SIMULATEMAP_H
