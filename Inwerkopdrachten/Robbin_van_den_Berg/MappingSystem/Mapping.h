#ifndef MAPPING_H
#define MAPPING_H
#include <QString>
#include <QVector>

class Mapping
{
public:
    //! The mapping constructor
    /*!
        Initialize the map and the default active object (0=Free)
    */
    Mapping();
    ~Mapping();
    //! The save map function
    /*!
        Save the map at a chosen destination with the given filename
        @param filename: The location and name where to save the file to
    */
    bool saveMap(QString fileName);
    //! The load map function
    /*!
        Load the map from a chosen location
        @param filename: The location from where to load the file
    */
    bool loadMap(QString fileName);
    //! Place an object in the map
    /*!
        Insert the current active object in the map at the given x/y coordinates
        @param posX: The X coordinate
        @param posY: The Y coordinate
    */
    bool setObject(int posX, int posY);
    //! Set an active object
    /*!
        Set the current active object
        @param obj: the number of the obj to set active (0=Free,1=Quadcopter,2=Rosbee,3=ATV,4=Wall)
    */
    int setActiveObject(int obj);
    //! Get the current map
    /*!
        Retrieve the current map which has the objects in it
    */
    QVector< QVector<int> > getMap();
private:
    static const int size = 20;
    QVector< QVector<int> > grid;
    int activeObject;
};
#endif // MAPPING_H
