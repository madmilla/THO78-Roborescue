#include <QApplication>
#include <QPainter>
#include <QGraphicsView>

#include "mainWindow.h"

int main(int argc, char *argv[])
{
    for(int i = 1; i<argcv ; i++){
        if(argv[i] == "-noGUI"){
            std::cout<<"noGUI enforced";
            return EXIT_SUCCESS;
        }
    }

    QApplication app(argc, argv);
    mainWindow mainWin;
    mainWin.show();
    return app.exec();
}
