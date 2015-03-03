#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <vector>
#include "mapCreator.h"

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
    void showMap(QString fileName);
    QMenu *fileMenu;
    QAction *newAct;
    QAction *openAct;
    std::vector<QVBoxLayout *> verticalLines;
    std::vector<QHBoxLayout *> horizontalLines;

private slots:
    void newFile();
    void open();

};

#endif // MAINWINDOW_H
