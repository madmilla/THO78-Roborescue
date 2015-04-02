#-------------------------------------------------
#
# Project created by QtCreator 2015-02-25T00:20:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapping
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    map.h

FORMS    += mainwindow.ui

DISTFILES += \
    objects \
    test \
    x

RESOURCES += \
    map.qrc
