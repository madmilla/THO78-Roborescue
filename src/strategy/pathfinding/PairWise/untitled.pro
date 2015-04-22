#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T16:32:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    testcopter.cpp \
    dimension.cpp \
    waypoint.cpp \
    route.cpp \
    testatv.cpp \
    pairwisemove.cpp

HEADERS  += \
    testcopter.h \
    dimension.h \
    waypoint.h \
    route.h \
    testatv.h \
    pairwisemove.h

FORMS    += mainwindow.ui
