#-------------------------------------------------
#
# Project created by QtCreator 2015-02-23T09:57:03
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mapping
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    map.hpp \
    noncopyable.hpp

FORMS    += mainwindow.ui
