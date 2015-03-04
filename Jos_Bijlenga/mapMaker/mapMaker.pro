#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T13:07:01
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maplogic.cpp \
    tester.cpp

HEADERS  += mainwindow.h \
    maplogic.h \
    tester.h

FORMS    += mainwindow.ui

RESOURCES +=
