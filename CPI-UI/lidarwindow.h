#ifndef LIDARWINDOW_H
#define LIDARWINDOW_H

#include <QMainWindow>
#include "lidar.h"

namespace Ui {
class lidarwindow;
}

class lidarwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit lidarwindow(QWidget *parent = 0);
    ~lidarwindow();

private slots:


    void handleButtonLidar();

    void LidarMissionRunning(bool isRunning);

    void setRpm(int Rpm);

private:
    Ui::lidarwindow *ui;
};

#endif // LIDARWINDOW_H
