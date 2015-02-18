/// @file Main.cpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#include "Window.hpp"
#include <QApplication>

///Entry point for application.
int main(int argc, char *argv[]){
    //New application.
    QApplication a(argc, argv);
    //New window.
    Window w;
    //Show window.
    w.show();
    //Run forever:
    return a.exec();
}
