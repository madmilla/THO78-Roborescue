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
    mainwindow.cpp \
    tester.cpp \
    gridpart.cpp

HEADERS  += map.h \
    mapreadfailure.h \
    mainwindow.h \
    test.h \
    tester.h \
    gridpart.h

FORMS += \
    mainwindow.ui