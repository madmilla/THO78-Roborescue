#ifndef WINDOW
#define WINDOW
#include "grid.h"

#include <QWidget>

class QVBoxLayout;
class QMenuBar;
class QMenu;
class QAction;

class Window : public QWidget {
public:
    Window(Grid &grid);
    const void load();
    const void create();
    const void save();
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
