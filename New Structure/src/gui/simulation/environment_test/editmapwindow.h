#ifndef EDITMAPWINDOW_H
#define EDITMAPWINDOW_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"
#include "values.h"

namespace Ui {
class EditMapWindow;
}

class EditMapWindow : public QDialog
{
    Q_OBJECT

public:
    //!The Contructor for the EditMapWindow
    /*!
    @param Map: the ui needs to know the map to use his functions
    */
    explicit EditMapWindow(Map* map, QWidget *parent = 0);
    ~EditMapWindow();

private slots:
    //! Used when the obstacle button gets clicked
    void on_obstacleButton_clicked();
    //! Used when the save button gets clicked
    void on_saveMapButton_clicked();
    //! Used when the none button gets clicked
    void on_noneButton_clicked();

private:
    Ui::EditMapWindow *ui;
    Qt::GlobalColor getColorById(int id);//Get a color
    void paintEvent(QPaintEvent *e);//Paint the window
    void mousePressEvent(QMouseEvent * event);//Used to handle moude presses
    bool mousePressed = true;
    Map *map;
    int selected = Values::OBSTACLE;
    int objectx = 0;
    int objecty = 0;
    int drawWidth = Values::DRAWWIDTH;//size of the drawing space
    int drawHeight = Values::DRAWHEIGHT;//size of the drawing space
};

#endif // EDITMAPWINDOW_H
