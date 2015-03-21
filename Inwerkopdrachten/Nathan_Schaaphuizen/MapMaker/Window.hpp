/// @file Window.hpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include "Widget.hpp"
#include "MapUi.hpp"
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QSignalMapper>
#include <QFileDialog>

/// Class Window
/// @brief The main window for the application.
///
/// Creates the main application window.
/// The window creates and manages the user interface.
/// With exception of the widget which handles its own events.
class Window : public QMainWindow{
    Q_OBJECT

private:
    /// Widget we are drawing on.
    Widget widget;

    /// Menu bar
    QMenuBar menuBar;

    /// File menu
    QMenu fileMenu;
    /// New action
    QAction fileMenuNew;
    /// Open action
    QAction fileMenuOpen;
    /// Save action
    QAction fileMenuSave;
    /// Save As action
    QAction fileMenuSaveAs;
    /// Export action
    QAction fileMenuExport;
    /// Exit action
    QAction fileMenuExit;

    /// Edit menu
    QMenu editMenu;
    /// Grid action
    QAction editMenuGrid;
    /// Size submenu
    QMenu editMenuSizeMenu;
    /// 10x10 submenu action
    QAction editMenuSizeMenu10;
    /// 20x20 submenu action
    QAction editMenuSizeMenu20;
    /// 40x40 submenu action
    QAction editMenuSizeMenu40;
    /// 80x80 submenu action
    QAction editMenuSizeMenu80;
    /// Grid action
    QAction editMenuMerge;

    /// Map we are using.
    MapUi map;
    /// Filename/Path of the currently loaded file.
    QString fileName;
    /// Message box to display any errors.
    QMessageBox errorBox;

private slots:
    /// Function called when new triggered in the menu bar.
    void newf();
    /// Function called when open triggered in the menu bar.
    void open();
    /// Function called when exit triggered in the menu bar.
    void exit();
    /// Function called when export triggered in the menu bar.
    void exportf();
    /// Function called when save triggered in the menu bar.
    void save();
    /// Function called when save as triggered in the menu bar.
    void saveAs();
    /// Function called when grid triggered in the menu bar.
    void grid();
    /// Function called when one of the sub actions from the edit menu is triggered in the menu bar.
    void resize(int size);
    /// Function called when merge triggered in the menu bar.
    void merge();

public:
    /// Constructor
    ///
    /// Creates new instance of Window.
    /// Also initilizes a buttload of attributes.
    explicit Window(QWidget *parent = 0);

};

#endif // _WINDOW_HPP
