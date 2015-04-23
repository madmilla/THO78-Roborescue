#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T16:32:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

SOURCES +=\
    dimension.cpp \
    waypoint.cpp \
    route.cpp \
    pairwisemove.cpp \
    ../../../tests/auto/PairWise-test/main.cpp \
    ATV.cpp \
    quadCopter.cpp

HEADERS  += \
    dimension.h \
    waypoint.h \
    route.h \
    pairwisemove.h \
    ATV.h \
    quadCopter.h

