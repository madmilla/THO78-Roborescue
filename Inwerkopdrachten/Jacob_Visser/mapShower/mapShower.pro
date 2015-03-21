#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T20:40:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapShower
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Libs/mapCreator.cpp

HEADERS  += mainwindow.h \
    Libs/mapCreator.h

FORMS    += mainwindow.ui

Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui
