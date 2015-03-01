#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class MapDisplayWidget;
class Map;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString filename;
    MapDisplayWidget* display;
    Map *currentMap;
    bool saved;
    void saveMap();
private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
};

#endif // MAINWINDOW_H
