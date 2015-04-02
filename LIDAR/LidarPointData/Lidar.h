#ifndef LIDAR_H
#define LIDAR_H
#include "include/rplidar.h" //RPLIDAR standard sdk, all-in-one header
#include <vector>

using namespace rp::standalone::rplidar;

//! Data structure for scan point
/*!
    The data structure for a single point scanned by the lidar
*/
struct scanDot
{
    uint8_t quality; //! Quality of the point scanned
    float angle; //! Angle of the lidar (0-360)
    float dist; //! Distance of the point scanned
};

class Lidar
{
public:
    //! The Contructor for the Lidar
    /*!
        Initialize the Lidar and set the default settings (baudrate)
        @param opt_com_path: Path to the com port which the lidar is attached to.
    */
    Lidar(const char *opt_com_path);
    //! Check the health of the RPLidar
    /*!
        Check the health and if an error is detected execute a software reboot.
        @return bool: true if OK false otherwise
    */
    bool checkRPLIDARHealth();
    //! Start a single scan with the lidar
    /*!
        A 360deg scan with the lidar which output the points found, points with quality 0
        will be filtered out. Also stores the scanData in a vector
        which contains all the data from single scans made.
        @return std::vector<scanDot>: vector with the scandata (angle,distance,quality)
    */
    std::vector<scanDot> startSingleLidarScan();
    //! Stop a lidar scan
    /*!
        Ask the RPLIDAR core system to stop the current scan operation and enter idle state
    */
    void stopLidarScan();
    //! Dispose the Lidar Driver
    /*!
        Dispose the RPLIDAR Driver Instance specified by the drv parameter in order to free memory
    */
    void disposeLidarDriver();
    //! Connect the drivers with lidar
    /*!
        Open the specified serial port and connect to a target RPLIDAR device
    */
    void connectDriversLidar();
    //! Write (multiple) scan data to a file
    /*!
        Write all the data present in the scanData vector to a file
        @param fname The name of the output file (will be created)
    */
    void writeScanDataToFile(std::string fname);
    //! Get the scanData
    /*!
        Retrieve all the scanData present (can be from multiple scans)
        @return vector a vector with all the scandata
    */
    std::vector<scanDot> getScanData();
    //! Print the scandata to the console
    /*!
        Print all the scanData to the console (stderr)
    */
    void printScanData();

private:
    //! Path to the com port which the lidar is attached to.
    const char *opt_com_path;
    //! The baudrate used (For most RPLIDAR models, the baudrate should be set to 115200)
    _u32 opt_com_baudrate;
    //! Store results lidar operations
    u_result op_result;
    //! create the driver instance
    RPlidarDriver *drv;
    //! vector to store the scandata (angle,distance,quality)
    std::vector<scanDot> scanData;
};

#endif // LIDAR_H


