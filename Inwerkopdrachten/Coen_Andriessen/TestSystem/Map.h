#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QtGui>
#include <QMessageBox>
#include <QPainter>


class Map : public QWidget
{
public:
    Map(QWidget *parent = 0);
    ~Map();
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void setTile(int x, int y);
    void getMap(QString filename);
    QString myMap[20][20];
    QString quadCopterLocationX;
    QString quadCopterLocationY;
    int xLength, yLength;
    int blockWidth;
    int blockHeight;
};

#endif // MAP_H
