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

    void setRpm(int Rpm);

private:
    void lidarMissionRunning(bool isRunning);

    Ui::lidarwindow *ui;

    lidar * lidar;
};

#endif // LIDARWINDOW_H
