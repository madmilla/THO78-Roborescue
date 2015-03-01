#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T14:54:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Map_Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp \
    tile.cpp \
    mapdisplaywidget.cpp \
    mapgraphicsview.cpp \
    newdialog.cpp \
    discarddialog.cpp

HEADERS  += mainwindow.h \
    map.h \
    tile.h \
    mapdisplaywidget.h \
    mapgraphicsview.h \
    newdialog.h \
    discarddialog.h

FORMS    += mainwindow.ui \
    newdialog.ui \
    discarddialog.ui

RESOURCES +=

DISTFILES +=
