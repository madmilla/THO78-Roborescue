#include "mainwindow.h"
#include <QApplication>
#include "loader.h"
#include "QFileDialog"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();    //QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),"",tr("Files(*.*)"));
    return a.exec();
}
