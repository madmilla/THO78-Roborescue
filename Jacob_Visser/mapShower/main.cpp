#include "mainwindow.h"
#include "Libs/mapCreator.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#ifdef TEST
int main(int argc, char *argv[])
{
    bool error = false;

    //test map -1 size
    objectMap map = new objectMap(-1, -1, mapje);


}

#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;

    w.show();

    return a.exec();
}
#endif
