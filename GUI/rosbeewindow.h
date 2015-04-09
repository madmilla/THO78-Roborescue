#ifndef ROSBEEWINDOW_H
#define ROSBEEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "rosbee.h"

namespace Ui {
class RosbeeWindow;
}

/**
* @class  RosbeeWindow
* @author Wibren Wiersma (wibrenwiersma@hotmail.com)
* @date   April, 2015
* @brief  this class handles ui input from the RosbeeWindow
*/
class RosbeeWindow : public QMainWindow
{
    Q_OBJECT

public:
   /**
   *  Construts an RosbeeWindow
   *	@param rosbee pointer to the Rosbee object that needs to be controlled / displayed
   *  @param parent use this param if this is a sub window of some QWidget
   */
   explicit RosbeeWindow(Rosbee * rosbee, QWidget *parent = 0);
   /**
    * Deconstructs the rosbee window
    */
   ~RosbeeWindow();

private slots:
    void handleButton();
    void timerTick();
private:
    Rosbee * rosbee;
    Ui::RosbeeWindow *ui;
    QTimer * timer;

    void SetMissionRunning(bool is_mission_running);


};

#endif // ROSBEEWINDOW_H
