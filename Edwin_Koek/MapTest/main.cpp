#include "window.h"
#include "grid.h"
#include <QApplication>

using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Grid grid;
    Window widget(grid);
    widget.show();
    return app.exec();
}

