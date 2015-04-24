/*!
 *  \brief     mainWindow containing all GUI code for the mainWindow.
 *  \details   The mainWindow class is used for generating and handling the events of the mainWindow.
 *  \author    Danny Horvath - 1634676
 *  \author    Thomas Fink - 1634907
 *  \version   1.0
 *  \date      08-04-2015
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "editmapwindow.h"
#include "simulatemapwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    *   Default constructor of mainWindow.
    *   \brief Default constructor of mainWindow.
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
    *   Default destructor of mainWindow.
    *   \brief Default destructor of mainWindow.
    */
    ~MainWindow();

private slots:
    //! Used when the NewMap button gets clicked
    void on_newMapButton_clicked();
    //! Used when the editMap button gets clicked
    void on_editMapButton_clicked();
    //! Used when the Simulate button gets clicked
    void on_simulateButton_clicked();

private:
    //! Ui pointer for use with QT.
    Ui::MainWindow *ui;
    //! Map pointer containing map information.
    Map *map = 0;
    //! Editmapwindow for opening the editMapWindow.
    EditMapWindow* editMapWindow;
    //! Int containing the new map begin size.
    static const int newMapBeignSize = 100;
    //! Int containing minimal map size.
    static const int newMapMinSize = 10;
    //! Int containing maximal map size.
    static const int newMapMaxSize = 100;
    //! Int containing the map step size.
    static const int newMapStepSize = 10;
};

#endif // MAINWINDOW_H
