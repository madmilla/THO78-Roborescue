/*!
 *  \brief     Map class containing all logic code for the map.
 *  \details   The map class is used for storing, loading and making all map objects containing the information of a given map.
 *  \author    Danny Horvath - 1634676
 *  \author    Thomas Fink - 1634907
 *  \version   1.0
 *  \date      08-04-2015
 */

#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QTableWidget>
#include "simulatemap.h"

using namespace std;

class Map
{
public:
    /*!
    *   Map constructor with a given file.
    *   \brief Given a filename this constructor will read and convert a .map file to a map object.
    *   @param fileName the name of a .map file containing map information.
    */
    Map(string fileName);
    /*!
    *   Map constructor with given file, height and width.
    *   \brief This constructor is used for making a new map with a standard height & width.
    *   @param fileName the name of a .map file containing map information
    *   @param height the height of the map
    *   @param width the width of the map
    */
    Map(string fileName, int height, int width);
    /*!
    *   getMapContent gets all the information of a map.
    *   \brief This function gets and returns all information of a map object in a 2D-vector.
    *   @return std::vector<vector< int > > a 2D-vector containing all the map information.
    */
    vector<vector< int > > getMapContent();
    /*!
    *   setMapContent is used to set a map to the content of a given 2D-vector.
    *   \brief Sets al the data in the map to the data in a given 2D-vector containing ints.
    *   @param newMapLayout is a 2D-Vector containing ints with information about the map.
    */
    void setMapContent(vector<vector< int > > newMapLayout);
    /*!
    *   setMapObject sets a object at a given position.
    *   \brief Sets a spot at a given x and y position to the desired object.
    *   @param object is an int representing the desired object.
    *   @param x,y ints containg the x and y coordinates.
    */
    void setMapObject(int object, int y, int x);
    /*!
    *   getMapObject Gets the value of an object at a given position in the map.
    *   \brief Gets an object at the given x and y position and returns the value of this object.
    *   @param x,y are ints containing the x and y coordinates.
    *   @return returns an int containing the value of the found object return -1 if object not found.
    */
    int getMapObject(int y, int x);
    /*!
     * saveMap saves the map to a file.
     * \brief Saves all the content of a map to a .map file.
    */
    void saveMap();
    /*!
      * Default constructor of map.
      * \brief Default constructor of map, clearing memory etc.
    */
    ~Map();
    //! the width of the map from 1 to x
    int width;
    //! the width of the map from 1 to x
    int height;
    //! the filename
    string fileName;

private:
    //! The vector which contains all the data of the map by this template mapLayout[y][x].
    vector<vector< int > > mapLayout;
    //! Creates a new map given a fileName.
    void createNewMap(string fileName);
    //! Loads the map with the given filename.
    void loadMap(string fileName);
};

#endif // MAP_H
