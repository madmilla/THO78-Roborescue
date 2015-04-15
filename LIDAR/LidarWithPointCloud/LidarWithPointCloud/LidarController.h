#ifndef LIDARCONTROLLER_H
#define LIDARCONTROLLER_H

#include "Lidar.h"
#include "PointCloud.h"
#include <mutex>
#include <condition_variable>

class LidarController
{
public:
    //! The Contructor for the LidarThread
    /*!
        Initialize the LidarThread and set the lidar reference. QThread must be used
        to keep the GUI responsive to user input while scanning with the lidar
        @param &l: Reference to a Lidar instance
    */
    LidarController(Lidar &l);
    //! Run the thread
    /*!
        Lidar scans will be performed untill user stops or pause it in the GUI. Scan output
        will be shown in the GUI.
    */
    void run();
    //! Resume the thread
    /*!
        Resume the thread which will start the lidar to scan
    */
    void resume();
    //! Pause the thread
    /*!
        Pause the thread which will also will pause the lidar with scanning
    */
    void pause();
    //! Set counter which contains the number of scans to execute
    /*!
        Set the counter which contains the number of scans to execute
        if set to -1 the lidar w
    */
    void setNumberOfScans(int number);
    //! Reset counter which contains the number of scans to execute
    /*!
        Reset the counter which contains the number of scans to execute
    */
    void resetNumberOfScans();
    //! Reset counter which contains the number of scans that are executed
    /*!
        Reset the counter which contains the number of scans that are executed
    */
    void resetScanCount();
    //! A boolean to stop the thread
    /*!
        Default to false, when set to true the thread will be stopped an terminated
        (after current lidar is finished)
    */
    bool Stop;

private:
    //! Reference to a lidar instance
    Lidar &lidar;
    //! Provide access serialization between threads
    std::mutex csync;
    //! Provide a condition variable for synchronizing threads
    std::condition_variable cpauseCond;
    //! True if thread is paused, false otherwise
    bool isPaused;
    //! Pointcloud object
    Pointcloud pCloud;
    //! Number of scans to execute
    int numberOfScans;
    //! Amount of scans that are executed
    int scanCount;
};

#endif // LIDARCONTROLLER_H
