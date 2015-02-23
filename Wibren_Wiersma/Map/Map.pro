#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T14:28:26
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Map
TEMPLATE = app


SOURCES += map.cpp \
    mapreadfailure.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS  += map.h \
    mapobject.h \
    mapreadfailure.h \
    mainwindow.h

FORMS += \
    mainwindow.ui