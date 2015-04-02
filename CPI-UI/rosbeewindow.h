#ifndef ROSBEEWINDOW_H
#define ROSBEEWINDOW_H

#include <QDockWidget>
#include <QTimer>
#include "rosbee.h"

namespace Ui {
class RosbeeWindow;
}

class RosbeeWindow : public QDockWidget
{
    Q_OBJECT

public:
    explicit RosbeeWindow(Rosbee * rosbee, QWidget *parent = 0);
    ~RosbeeWindow();

private slots:
    void handleButton();
    void timerTick();
private:
    Ui::RosbeeWindow *ui;
    QTimer * timer;

    void SetMissionRunning(bool is_mission_running);

    Rosbee * rosbee;
};

#endif // ROSBEEWINDOW_H
