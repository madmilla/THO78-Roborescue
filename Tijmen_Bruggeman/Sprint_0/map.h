#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QVector>

namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();
    void show_map();
    void setMap(QVector<QString> v, QString fileName);
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
    Ui::Map *ui;
    void paintEvent(QPaintEvent *e);
    QVector<QString> current_map;
    int screen_height = 480;
    int screen_witdh = 480;
    void mousePressEvent(QMouseEvent * event);
    bool editing = false;
    int objectSize;
    QString fileName;
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
