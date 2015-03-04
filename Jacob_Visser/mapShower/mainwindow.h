#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <vector>
#include <QListWidgetItem>
#include <QLabel>
#include <QDebug>
#include <cstddef>
#include "Libs/mapCreator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void showMap(objectMap& map);
    QString getIcon(object obj);
    objectMap map;
    QMenu *fileMenu = nullptr;
    QAction *newAct = nullptr;
    QAction *openAct = nullptr;
    QWidget tileMap;
    QVBoxLayout verticalLines;
    std::vector<QHBoxLayout *> horizontalLines;

private slots:
    void newFile();
    void open();

};

#endif // MAINWINDOW_H
