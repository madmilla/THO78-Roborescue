#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QVector>
#include "map.h"

namespace Ui {
class MapEditor;
}

class MapEditor : public QDialog
{
    Q_OBJECT

public:
    explicit MapEditor(QWidget *parent = 0);
    ~MapEditor();
    void show_map();
    void print();
    void setMap(Map * newMap);

private slots:
    void on_pushButton_clicked();

    void on_grass_clicked();

    void on_car_clicked();

    void on_water_clicked();

    void on_wall_clicked();

    void on_stone_clicked();

    void on_saveButton_clicked();

    void on_saveAsButton_clicked();

    void on_tree_clicked();

    void on_quad_clicked();

private:
    QChar current_object = '4';
    Ui::MapEditor *ui;
    void paintEvent(QPaintEvent *e);
    Map * map = NULL;
    int screen_height = 480;
    int screen_witdh = 480;
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    bool editing = false;
    bool mousePressed = false;
    int objectSize;
    enum Objects{
        Car = '7',
        Grass = '4',
        Stone = '2',
        Wall = '3',
        Unknown = 'X',
        Water = '1',
        Quad = '0',
        Tree = '5'
    };
};

#endif // MAP_H
