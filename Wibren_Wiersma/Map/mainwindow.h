#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"

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
    void openFile();
    void createFile();
    void saveFile();
    void closeFile();
private:
    void openFile(std::string filename);
    void setDisplayingFile(bool value);

    Ui::MainWindow *ui;
    Map * map;
    bool isDisplayingFile;
};

#endif // MAINWINDOW_H
