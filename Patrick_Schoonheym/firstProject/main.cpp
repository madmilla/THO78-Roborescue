#include "mainwindow.h"
#include <QApplication>
#include "test.h"

int main(int argc, char* argv[])
{
    if(argc > 1 && strcmp(argv[1], "test") == 0) {
        Test test{"C:/Users/Patrick/Documents/firstProject/maps/fout.map"};
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
