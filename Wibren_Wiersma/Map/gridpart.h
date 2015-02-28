#ifndef GRIDPART_H
#define GRIDPART_H

#include <QPalette>
#include <QWidget>
#include <QLabel>

class GridPart
{
public:
    GridPart(unsigned int data, QWidget * parent);

    QWidget * getWidget(){
        return &widget;
    }
private:
    QPalette palette;
    QLabel widget;
    QColor normalColor;
};

#endif // GRIDPART_H
