#-------------------------------------------------
#
# Project created by QtCreator 2015-02-13T11:07:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Algemeen_Inwerken
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp\
    mainwindow.cpp \
    map.cpp \
    mapwidget.cpp \
    maptester.cpp

HEADERS  += \
    mapwidget.h \
    mainwindow.h \
    map.h \
    maptester.h

FORMS    += mainwindow.ui

release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
