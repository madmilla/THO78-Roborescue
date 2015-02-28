#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T13:59:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firstProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    map.h

FORMS    += mainwindow.ui \
    map.ui

RESOURCES += \
    textures.qrc
