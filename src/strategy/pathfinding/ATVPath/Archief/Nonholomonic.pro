#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T13:51:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nonholomonic
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    pathfinding.cpp \
    node.cpp \
    rotation30.cpp \
    map.cpp \
    mapitem.cpp \
    display.cpp

HEADERS  += mainwindow.h \
    pathfinding.h \
    vector.h \
    node.h \
    rotationoption.h \
    rotation30.h \
    map.h \
    mapitem.h \
    display.h

FORMS    += mainwindow.ui
