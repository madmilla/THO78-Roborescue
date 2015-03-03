#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T10:25:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = map
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    loader.cpp \
    mywidget.cpp \
    map.cpp \
    tile.cpp

HEADERS  += mainwindow.h \
    loader.h \
    mywidget.h \
    map.h \
    tile.h

FORMS    += mainwindow.ui
