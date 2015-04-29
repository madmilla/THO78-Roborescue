#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T08:44:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Map
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp \
    mapcanvas.cpp \
    quadroute.cpp

HEADERS  += mainwindow.h \
    map.h \
    mapcanvas.h \
    quadroute.h

FORMS    += mainwindow.ui
