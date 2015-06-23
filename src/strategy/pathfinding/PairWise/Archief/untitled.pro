#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T16:32:52
#
#-------------------------------------------------
CONFIG += c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app



SOURCES +=\
    pairwisemove.cpp \
    ../../../tests/auto/PairWise-test/main.cpp \
    ../../../map/MapStructure/map.cpp \
    ../../../map/MapStructure/point.cpp \
    ../../../map/MapStructure/line.cpp \
    ../../../map/MapStructure/polygon.cpp \
    ../Stop-them-spaces/aStar.cpp \
    ../../Common/ATV.cpp \
    ../../Common/dimension.cpp \
    ../../Common/quadCopter.cpp \
    ../../Common/route.cpp \
    ../../Common/waypoint.cpp

HEADERS  += \
    pairwisemove.h \
    ../../../map/MapStructure/map.hpp \
    ../../../map/MapStructure/line.hpp \
    ../../../map/MapStructure/point.hpp \
    ../../../map/MapStructure/polygon.h \
    ../Stop-them-spaces/aStar.h \
    ../../Common/ATV.h \
    ../../Common/dimension.h \
    ../../Common/quadCopter.h \
    ../../Common/route.h \
    ../../Common/waypoint.h

