#include "rosbeewindow.h"
#include "quadcopterwindow.h"
#include "tests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc > 1 && std::string(argv[1]) == "--runtests"){
        Tests tests;
        return tests.run();
    }

    QApplication a(argc, argv);
    Rosbee rosbee;
    RosbeeWindow w(&rosbee);
    w.show();
    QuadCopterWindow q;
    q.show();

    return a.exec();
}
