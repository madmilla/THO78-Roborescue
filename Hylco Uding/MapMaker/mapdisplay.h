#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
namespace Ui {
class MapDisplay;
}

class MapDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit MapDisplay(QWidget *parent = 0);
    ~MapDisplay();
    void setMap(QJsonObject json);
private:
    std::map<QString,QBrush> Types;
    Ui::MapDisplay *ui;
    void paintEvent(QPaintEvent * e);
    void mousePressEvent(QMouseEvent * event);
    QJsonObject  json;
};

#endif // MAPDISPLAY_H
