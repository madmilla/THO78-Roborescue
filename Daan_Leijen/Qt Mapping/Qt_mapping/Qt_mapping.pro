#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T16:51:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   -= x86_64
TARGET = Qt_mapping
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapProcessor.cpp \
    mapRectangle.cpp

HEADERS  += mainwindow.h \
    mapProcessor.h \
    mapRectangle.h

FORMS    += mainwindow.ui
