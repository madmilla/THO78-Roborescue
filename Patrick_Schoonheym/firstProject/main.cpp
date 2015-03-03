#include "mainwindow.h"
#include <QApplication>
#include "test.h"

int main(int argc, char** argv)
{
    if(argv[1] == "test") {
        Test test{"test.map"};
        return test.start();
    }
    else {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
