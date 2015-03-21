#include "mainwindow.h"
#include "mapProcessor.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    if (argc == 1){
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
    }
    else {
        if (std::string(argv[1]) == "t") { //test argument
            mapProcessor m;
            if (m.processMap(QString(), 0, 0)) {
                qDebug() << "ERROR: mapProcessor accepts empty file!";
                return -1;
            }
            if (!m.processMap(QString("empty_map.txt"), 0, 0)) {
                qDebug() << "ERROR: mapProcessor cannot handle empty map!";
                return -2;
            }
            if (!m.processMap(QString("filled_map.txt"), 0, 0)) {
                qDebug() << "ERROR: mapProcessor cannot handle correct filled map!";
                return -3;
            }
            if (!m.processMap(QString("filled_map_incorrect.txt"), 0, 0)) {
                qDebug() << "ERROR: mapProcessor accepts incorrectly filled map!";
                return -4;
            }
            qDebug() << "Success! mapProcessor passed all tests!";
            return 0;
        }
    }
}
