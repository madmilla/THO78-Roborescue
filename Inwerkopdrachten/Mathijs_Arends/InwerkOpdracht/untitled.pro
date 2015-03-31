#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T16:32:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    loader.cpp \
    map.cpp \
    tile.cpp \
    centerwidget.cpp \
    object.cpp

HEADERS  += mainwindow.h \
    widget.h \
    loader.h \
    map.h \
    tile.h \
    centerwidget.h \
    object.h

FORMS    += mainwindow.ui
