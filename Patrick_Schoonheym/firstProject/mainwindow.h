#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <vector>
#include <string>
#include "map.h"
#include "gui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addImage(const QString & name);

private slots:
    void on_openFileButton_clicked();

    void on_StartButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<QPixmap> images;
    std::vector<Gui*> guis;
    QPoint SCREEN_SIZE;
    QString mapName;
    Map* map;
};

#endif // MAINWINDOW_H
