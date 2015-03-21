#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawWindow.h"
class mainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = 0);

signals:

public slots:
        void toggleGrid();
private:
        drawWindow drawwindow;
        QToolBar *windowSettingsToolBar;
        QAction *gridAction;
        void createActions();
        void createToolbar();
};

#endif // MAINWINDOW_H
