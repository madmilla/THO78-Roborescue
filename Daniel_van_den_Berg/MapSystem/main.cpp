#include <QApplication>
#include "mainwindow.h"
#include "Logic.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow window;
    window.show();
    Logic *logic = new Logic();
    delete logic;
    return app.exec();
}

