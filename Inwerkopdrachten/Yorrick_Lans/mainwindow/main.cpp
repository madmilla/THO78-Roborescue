#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include "mainwindow.h"
#include "test.h"

int main(int argc, char *argv[])
{
    bool runTest = false;
    if(argc > 1 && strcmp(argv[1], "-test") == 0 || runTest)
    {
        Test test;
        return test.runTests();
    }
    else
    {
        QApplication app(argc, argv);
        app.setApplicationName("map");
        MainWindow mainWin;
        mainWin.show();
        return app.exec();
    }
}
