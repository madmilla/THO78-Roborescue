#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "map.h"
namespace Ui {
class MapDisplay;
}

class MapDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit MapDisplay(int height, int width, QJsonObject json, QWidget *parent = 0);
    ~MapDisplay();
private:
    Ui::MapDisplay *ui;
    void paintEvent(QPaintEvent * e);
    void mousePressEvent(QMouseEvent * event);
    Map * map;

};

#endif // MAPDISPLAY_H
