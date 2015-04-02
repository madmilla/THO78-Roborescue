#ifndef LIDARTHREAD_H
#define LIDARTHREAD_H

#include "Lidar.h"
#include <QThread>
#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QString>

class LidarThread : public QThread
{
    Q_OBJECT
public:
    //! The Contructor for the LidarThread
    /*!
        Initialize the LidarThread and set the lidar reference. QThread must be used
        to keep the GUI responsive to user input while scanning with the lidar
        @param &l: Reference to a Lidar instance
    */
    LidarThread(Lidar &l);
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
    //! Create a QString with the all the data from 1 scan
    /*!
        Create a QString with the all the data from 1 scan
        @param data The scanData that must be printed
        @param i The number of the scan
        @return QString A QString with all data from 1 scan
    */
    QString printReadyData(std::vector<scanDot> data, int i);
    //! A boolean to stop the thread
    /*!
        Default to false, when set to true the thread will be stopped an terminated
        (after current lidar is finished)
    */
    bool Stop;

signals:
    //! Send a signal to update the GUI
    /*!
        Send a signal to the MainWindow to update the GUI with the given text
        @param text The text that must be shown in the GUI
    */
    void updateUI(const QString text);

private:
    //! Reference to a lidar instance
    Lidar &lidar;
    //! Provide access serialization between threads
    QMutex sync;
    //! Provide a condition variable for synchronizing threads
    QWaitCondition pauseCond;
    //! True if thread is paused, false otherwise
    bool isPaused;
};

#endif // LIDARTHREAD_H
