#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T13:30:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapviewer.cpp \
    map.cpp \
    fileloader.cpp \
    object.cpp \
    filewriter.cpp

HEADERS  += mainwindow.h \
    mapviewer.h \
    map.h \
    fileloader.h \
    object.h \
    filewriter.h

FORMS    += mainwindow.ui

DISTFILES += \
    map.map
