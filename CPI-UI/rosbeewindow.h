#ifndef ROSBEEWINDOW_H
#define ROSBEEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "rosbee.h"

namespace Ui {
class RosbeeWindow;
}

class RosbeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RosbeeWindow(Rosbee * rosbee, QWidget *parent = 0);
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
