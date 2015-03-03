#include "mainwindow.h"
#include <QApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    bool runTest = false;

    //If either the boolean runTest equals true or the '-test' argument has
    //been passed to this program start the testing procedure.
    if(runTest || (argc > 1 && strcmp(argv[1], "-test") == 0))
    {
        Test test;
        return test.runTests();
    }
    //Otherwise start the GUI application.
    else
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}
