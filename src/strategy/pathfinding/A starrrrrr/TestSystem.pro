#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T16:02:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Map.cpp \
    scanArea.cpp \
    Rosbee.cpp \
    mapCanvas.cpp \
    Test.cpp \
    MapSearchNode.cpp

HEADERS  += mainwindow.h \
    Logic.h \
    Map.h \
    scanArea.h \
    Rosbee.h \
    mapCanvas.h \
    Test.h \
    fsa.h \
    stlastar.h \
    MapSearchNode.h

FORMS    += mainwindow.ui

DISTFILES += \
    Mapping.txt

QMAKE_CXXFLAGS = -std=c++11
