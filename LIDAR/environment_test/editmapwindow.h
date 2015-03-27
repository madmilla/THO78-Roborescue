#ifndef EDITMAPWINDOW_H
#define EDITMAPWINDOW_H

#include <QDialog>
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
    Map *map;
    QVector<QVector< int > > mapLayout;
};

#endif // EDITMAPWINDOW_H
