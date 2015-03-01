#include "mainwindow.h"

#include <QAction>
#include <QToolBar>

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent)
{

    drawwindow.show();
    setCentralWidget(&drawwindow);
    createActions();
    createToolbar();
}

void mainWindow::createToolbar(){
    windowSettingsToolBar = addToolBar(tr("window settings"));
    windowSettingsToolBar->addAction(gridAction);
}


void mainWindow::createActions(){
    gridAction = new QAction(QIcon(":/icons/grid.png"), tr("&Grid"), this);
    gridAction->setStatusTip(tr("Toggle the grid"));
    connect(gridAction, SIGNAL(triggered()), this, SLOT(toggleGrid()));
}

void mainWindow::toggleGrid(){
    drawwindow.toggleGrid();
}
