#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ObjectMap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ObjectMap & objectMap, QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionClear_clicked();

    void on_actionSave_clicked();

    void on_actionReload_clicked();

    void on_heightSelection_valueChanged(int arg1);

    void on_radioDriveable_toggled(bool checked);

    void on_radioStaticObject_toggled(bool checked);

    void on_map_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_vehicleButton_clicked();

private:

    void refreshMap();

    Ui::MainWindow *ui;

    ObjectMap & objectMap;
};

#endif // MAINWINDOW_H
