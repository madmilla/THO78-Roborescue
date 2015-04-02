#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "Lidar.h"
#include "LidarThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //! Start scan button clicked
    void on_StartScan_triggered();
    //! Stop scan button clicked
    void on_StopScan_triggered();
    //! Pause scan button clicked
    void on_PauseScan_triggered();
    //! Resume scan button clicked
    void on_ResumeScan_triggered();
    //! Save scan button clicked
    void on_SaveScan_triggered();
    //! Append scandata to GUI
    void appendToTextView(const QString text);

private:
    //! Pointer to UI object
    Ui::MainWindow *ui;
    //! Lidar object
    Lidar lidar;
    //! LidarThread object
    LidarThread lthread;
};

#endif // MAINWINDOW_H
