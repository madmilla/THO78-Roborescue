/*!
 *  \brief     Class containing all logic of the checkpoint class.
 *  \details   The checkpoint class is used for generating checkpoints inside a map to simulate lidar scans.
 *  \author    Danny Horvath - 1634676
 *  \author    Thomas Fink - 1634907
 *  \version   1.0
 *  \date      15-04-2015
 */

#ifndef CHECKPOINT_H
#define CHECKPOINT_H


class checkPoint
{
private:
    int checkPointx = 0;
    int checkPointy = 0;
public:
    /*!
    *   Default constructor of checkPoint class.
    *   \brief Default constructor of checkPoint class.
    */
    checkPoint();
    /*!
    *   Constructor of checkPoint class containing x and y coordinates.
    *   \brief Custom constructor of checkPoint class containing an x and y coordinate where the checkpoint will be put.
    *   @param x,y coordinates of the checkpoint inside the 2D-map.
    */
    checkPoint(int x, int y);
    /*!
    *   setCoordinate method sets the coordinates of a checkPoint object.
    *   \brief Sets the coordinates of a checkPoint object to the desired x and y coordinates.
    *   @param x,y coordinates the checkpoints needs to be set to inside the 2D-map.
    */
    void setCoordinates(int x, int y);
    /*!
    *   Sets the x coordinate.
    *   \brief Sets the x coordinate of a given checkPoint object to the desired x coordinate.
    *   @param x x-coordinate the checkpoint needs to be set to inside the 2D-map.
    */
    void setX(int x);
    /*!
    *   Sets the y coordinate.
    *   \brief Sets the y coordinate of a given checkPoint object to the desired y coordinate.
    *   @param y y-coordinate the checkpoint needs to be set to inside the 2D-map.
    */
    void setY(int y);
    /*!
    *   Gets the x coordinate.
    *   \brief Gets and returns the current x coordinate of the checkPoint.
    *   @return returns an int containing the current x coordinates of the checkPoint object.
    */
    int getX();
    /*!
    *   Gets the y coordinate.
    *   \brief Gets and returns the current y coordinate of the checkPoint.
    *   @return returns an int containing the current y coordinates of the checkPoint object.
    */
    int getY();
    /*!
    *   Default destructor.
    *   \brief Default destructor of the checkPoint class.
    */
    ~checkPoint();
};

#endif // CHECKPOINT_H
