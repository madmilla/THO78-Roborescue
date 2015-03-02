#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QVector>
#include <QGraphicsView>
#include <QDebug>

#include "mapRectangle.h"

class drawArea : public QGraphicsView{
public:
    drawArea();
    drawArea(QWidget* widget);

    ~drawArea();

    QVector <mapRectangle> getRectangles();
    void setRectangles(QVector <mapRectangle> rectangles);

    QVector <QString> getStrings();
    void setStrings(QVector <QString> strings);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QVector <mapRectangle> rectangles;
    QVector <QString> strings;
};

#endif // DRAWAREA_H
