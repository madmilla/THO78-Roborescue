#ifndef SIMULATEMAPWINDOW_H
#define SIMULATEMAPWINDOW_H

#include <QWidget>
#include "map.h"

namespace Ui {
class SimulateMapWindow;
}

class SimulateMapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SimulateMapWindow(Map *map, QWidget *parent = 0);
    ~SimulateMapWindow();

private slots:
    void on_simulateButton_clicked();

private:
    Ui::SimulateMapWindow *ui;
    Map *map;
};

#endif // SIMULATEMAPWINDOW_H
