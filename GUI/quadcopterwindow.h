#ifndef QUADCOPTERWINDOW_H
#define QUADCOPTERWINDOW_H

#include <QMainWindow>
#include "Listener.h"
#include "StatusText.h"

class Quadcopter;

namespace Ui {
class QuadCopterWindow;
}

class QuadCopterWindow : public QMainWindow, public Listener
{
    Q_OBJECT

public:
    explicit QuadCopterWindow( Quadcopter& quadcopter, QWidget *parent = 0);
    ~QuadCopterWindow();

private slots:

    void on_sendMaxAltitudeButton_clicked();

    void on_armButton_clicked();

    void on_takeOff_LandButton_clicked();

    void on_restartButton_clicked();

    void on_abortButton_clicked();

    void on_sendButton_clicked();

    void on_forwardButton_pressed();

    void on_rightButton_pressed();

    void on_backwardButton_pressed();

    void on_leftButton_pressed();

private:
    Ui::QuadCopterWindow *ui;
    Quadcopter& quadcopter;
	
    void notifyListener(Subject&, StatusText statusText) override;
};

#endif // QUADCOPTERWINDOW_H
