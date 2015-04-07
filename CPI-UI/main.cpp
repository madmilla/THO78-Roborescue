#include "mainwindow.h"
#include "tests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc > 1 && std::string(argv[1]) == "--runtests"){
        Tests tests;
        return tests.run();
    }

    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();

    return a.exec();
}
