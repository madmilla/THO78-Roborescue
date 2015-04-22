/*!
 *  \brief     editMapWindowClass containing all GUI code for the editMapWindow.
 *  \details   The EditMapWindow class is used for generating and handling the events of the EditMapWindow.
 *  \author    Danny Horvath - 1634676
 *  \author    Thomas Fink - 1634907
 *  \version   1.0
 *  \date      08-04-2015
 */

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
    /*!
    *   Constructor of editMapWindow
    *   \brief Constructor with a map object as parameter for drawing the map on the GUI
    *   @param map the map object containing the information for the GUI to draw
    */
    explicit EditMapWindow(Map* map, QWidget *parent = 0);
    /*!
    *   Default destructor of editMapWindow
    *   \brief Default destructor of editMapWindo.
    */
    ~EditMapWindow();

private slots:
    //! Used when the obstacle button gets clicked
    void on_obstacleButton_clicked();
    //! Used when the save button gets clicked
    void on_saveMapButton_clicked();
    //! Used when the none button gets clicked
    void on_noneButton_clicked();

private:
    //! A Uipointer used by QT.
    Ui::EditMapWindow *ui;
    //! Used for determining a color.
    Qt::GlobalColor getColorById(int id);
    //! PaintEvent is used for painting the window with it's contents.
    void paintEvent(QPaintEvent *e);
    //! MousePressEvent is used for handling all mouspresses inside the window.
    void mousePressEvent(QMouseEvent * event);
    //! Bool used for checking if a mouse button is clicked.
    bool mousePressed = true;
    //! Pointer to a given map to store the map information in.
    Map *map;
    //! Sets the selected object to the value of an obstacle.
    int selected = Values::OBSTACLE;
    //! Contains the x coordinate of an object.
    int objectx = 0;
    //! Contains the y coordinate of an object.
    int objecty = 0;
    //! Containts the width of the drawing space.
    int drawWidth = Values::DRAWWIDTH;
    //! Containts the height of the drawing space.
    int drawHeight = Values::DRAWHEIGHT;
};

#endif // EDITMAPWINDOW_H
