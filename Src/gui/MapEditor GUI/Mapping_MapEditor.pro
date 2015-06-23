#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T15:18:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mapping_MapEditor
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    composedpolygon.cpp \
    point.cpp \
    polyobject.cpp \
    storage.cpp \
    square.cpp

HEADERS  += mainwindow.h \
    composedpolygon.h \
    point.h \
    polyobject.h \
    storage.h \
    square.h

FORMS    += mainwindow.ui
