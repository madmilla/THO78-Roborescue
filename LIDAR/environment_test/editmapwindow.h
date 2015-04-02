#ifndef EDITMAPWINDOW_H
#define EDITMAPWINDOW_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"

namespace Ui {
class EditMapWindow;
}

class EditMapWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditMapWindow(Map* map, QWidget *parent = 0);
    void showMap(Map* map);
    ~EditMapWindow();

private slots:
    void on_obstacleButton_clicked();

    void on_saveMapButton_clicked();

private:
    Ui::EditMapWindow *ui;
    Qt::GlobalColor getColorById(int id);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent * event);
    bool mousePressed;
    Map *map;
};

#endif // EDITMAPWINDOW_H
