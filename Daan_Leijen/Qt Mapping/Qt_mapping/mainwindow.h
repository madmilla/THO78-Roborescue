#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include "mapProcessor.h"
#include <QThread>

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
    void exit();

    void openFile();

private:
    mapProcessor m;
    Ui::MainWindow *ui;
    QString mapFile;
};

#endif // MAINWINDOW_H
