#include "mainwindow.h"
#include <QApplication>
#include "Mapping.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(480, 480);
    Mapping mapping;
    w.show();

    return a.exec();
}
