TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    areacoveringalgorithm.cpp \
    arraymap.cpp \
    dimension.cpp \
    route.cpp \
    testcopter.cpp \
    waypoint.cpp \
    databaseconnector.cpp \
    point.cpp \
    /../../../../deps/incl/mysqlcppconn \
    /../../../../deps/incl/boost

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    areacoveringalgorithm.h \
    arraymap.h \
    dimension.h \
    route.h \
    testcopter.h \
    waypoint.h \
    databaseconnector.h \
    point.hpp \
    /../../../../deps/incl/mysqlcppconn \
    /../../../../deps/incl/boost



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../deps/lib/mysqlcppconn/windows/x64(64 bit)/ -lmysqlcppconn
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../deps/lib/mysqlcppconn/windows/x64(64 bit)/ -lmysqlcppconnd
else:unix: LIBS += -L$$PWD/../../../../deps/lib/mysqlcppconn/windows/x64(64 bit)/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../../../deps/incl/mysqlcppconn/
DEPENDPATH += $$PWD/../../../../deps/lib/mysqlcppconn/windows/x64(64 bit)
