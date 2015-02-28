#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <vector>
#include <QTextStream>
#include <string>
#include <QTableView>
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
    void readFile(const QString & name);

private slots:
    void on_openFileButton_clicked();

    void on_StartButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<QString> map_data;
    std::vector<Map*> maps;
};

#endif // MAINWINDOW_H
