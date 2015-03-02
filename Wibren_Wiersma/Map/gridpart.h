#ifndef GRIDPART_H
#define GRIDPART_H

#include <QPalette>
#include <QWidget>
#include <QTableWidgetItem>
#include "map.h"

class GridPart
{
public:
    GridPart(unsigned int data);

    QTableWidgetItem * getWidget();

    static void changeData(unsigned int newData, QTableWidgetItem * twi);
private:
    QColor normalColor;
};

#endif // GRIDPART_H
