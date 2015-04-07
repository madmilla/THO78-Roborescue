#ifndef QUADCOPTERWINDOW_H
#define QUADCOPTERWINDOW_H

#include <QMainWindow>
#include "quadcopter.h"

namespace Ui {
class QuadCopterWindow;
}

class QuadCopterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuadCopterWindow(QWidget *parent = 0);
    ~QuadCopterWindow();

private slots:

    void on_toggleControlModeButton_clicked();

    void on_sendMaxAltitudeButton_clicked();

    void on_armButton_clicked();

    void on_takeOff_LandButton_clicked();

    void on_shutdownButton_clicked();

    void on_abortButton_clicked();

    void on_sendButton_clicked();

    void on_forwardButton_pressed();

    void on_rightButton_pressed();

    void on_backwardButton_pressed();

    void on_leftButton_pressed();

private:
    Ui::QuadCopterWindow *ui;
    Quadcopter *qc;
};

#endif // QUADCOPTERWINDOW_H
