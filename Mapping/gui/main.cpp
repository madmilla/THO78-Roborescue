#include <QApplication>
#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("Roborescue");
    app.setApplicationName("Roborescue map visualizer");
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
