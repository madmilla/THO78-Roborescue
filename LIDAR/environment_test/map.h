#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QTableWidget>

using namespace std;
//! The map class
/*!
The object which will contain all map data
*/
class Map
{
public:
    //! The map constructor for an existing map
    /*!
    Create a map object from an existing file
    @param fileName: the filename of the map its file
    */
    Map(string fileName);
    //! The map constructor for a new map
    /*!
    Create a new map object
    @param fileName: the filename of the map its file
    @param height: the height of the map
    @param width: the width of the map
    */
    Map(string fileName, int height, int width);
    //! get all the data of a map
    /*!
    get all the data of a map returned in a vector
    @return std::vector<vector< int > >: the vector which will contain a
    vector with the data of the map

    */
    vector<vector< int > > getMapContent();
    //! set all the data of a map
    /*!
    set all the data of a map returned in a vector
    @param newMapLayout: is a std::vector<vector< int > > the vector which will contain a
    vector with the data of the map

    */
    void setMapContent(vector<vector< int > > newMapLayout);
    //! set an object on the map
    /*!
    set the data of an object in a specific place on the map
    @param object: is an int to specify what object needs to be set
    @param y: is an int to specify the y position
    @param x: is an int to specify the x position

    */
    void setMapObject(int object,int y, int x);
    //! set an object on the map
    /*!
    get the data of an object(int) in a specific place on the map
    @param y: is an int to specify the y position
    @param x: is an int to specify the x position
    @return int: object on the specified y and x position

    */
    int getMapObject(int y, int x);
    //! save the map to the file
    /*!
    this saves the content of the map to a file

    */
    void saveMap();
    int width = 0;//! the width of the map from 1 to x
    int height = 0;//! the width of the map from 1 to x
    string fileName;//! the filename
    ~Map();

private:
    vector<vector< int > > mapLayout;//! the vector which contains all the data of the map
    void createNewMap(string fileName);
    void loadMap(string fileName);
};

#endif // MAP_H
