#-------------------------------------------------
#
# Project created by QtCreator 2015-02-23T15:09:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapGrid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    exitDialog.cpp \
    optionsdialog.cpp \
    savedialog.cpp \
    loaddialog.cpp \
    mapdialog.cpp

HEADERS  += mainwindow.h \
    exitDialog.h \
    optionsdialog.h \
    savedialog.h \
    loaddialog.h \
    mapdialog.h

FORMS    += mainwindow.ui \
    exitDialog.ui \
    optionsdialog.ui \
    savedialog.ui \
    loaddialog.ui \
    mapdialog.ui
