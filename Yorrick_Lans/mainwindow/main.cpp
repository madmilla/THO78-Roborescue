#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("map");
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
