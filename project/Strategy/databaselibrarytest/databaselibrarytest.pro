TEMPLATE = app
CONFIG += console sql
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -lDatabaseConnectorLibrary

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += $$PWD/include/
INCLUDEPATH += $$PWD/include/QtSql/
INCLUDEPATH += $$PWD/include/QtCore/

LIBS += -L$$PWD/libs/windows/64bit
LIBS += -lDatabaseConnectorLibrary
