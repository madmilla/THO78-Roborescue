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
    Logic.cpp \
    Map.cpp

HEADERS  += mainwindow.h \
    Logic.h \
    Map.h

FORMS    += mainwindow.ui

DISTFILES += \
    Mapping.txt
