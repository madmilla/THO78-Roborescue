#ifndef LIDARWINDOW_H
#define LIDARWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "lidar.h"

/**
* @class   lidarwindow
* @author Thijs van Tiem  (thijsvantiem@gmail.com)
* @date   April, 2015
* @brief  the class that handles the lidarwindow and the buttons on it.
*/

namespace Ui {
class lidarwindow;
}

class lidarwindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    *   Creates the lidar object en sets the qwidget parent
    *	@param lidar * l create the lidar object
    *   @param QWidget * Parent tells if there are parents or not. there are no parents here.
    */
    explicit lidarwindow(lidar * l, QWidget *parent = 0);

    /**
    *   deconstructor lidarwindow();
    */
    ~lidarwindow();

private slots:


    void handleButtonLidar();

    void setRpm();
    void timerPassed();

private:
    void lidarMissionRunning(bool isRunning);
    Ui::lidarwindow *ui;
    lidar * l;
    QTimer * timer;



};

#endif // LIDARWINDOW_H
