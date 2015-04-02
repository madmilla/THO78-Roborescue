/// @file window.h
/// @author Edwin Koek
/// @version 1.0

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include "grid.h"

class QVBoxLayout;
class QMenuBar;
class QMenu;
class QAction;

class Window : public QWidget {
public:
    Window(Grid &grid);
    void load();
    void create();
    void save();
protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
private:
    QVBoxLayout *m_boxLayout;
    QMenuBar* m_menuBar;
    QMenu *m_fileMenu;
    QAction* m_new;
    QAction* m_save;
    QAction* m_load;
    QAction* m_exit;
    Grid& m_grid;
};

#endif // WINDOW
