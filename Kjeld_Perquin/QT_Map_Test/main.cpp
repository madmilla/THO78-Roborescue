#include "mainwindow.h"
#include <QApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    bool runTest = true;
    if(argc > 1 && strcmp(argv[1], "-test") == 0 || runTest)
    {
        Test test;
        return test.runTests();
    }
    else
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}
