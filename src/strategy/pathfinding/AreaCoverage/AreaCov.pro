TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
#INCLUDEPATH += "/../../../../deps/incl/mysqlcppconn/"
INCLUDEPATH = $$PWD/../../../../deps/incl/mysqlcppconn/
LIBS +=  "-L $$PWD../../../../deps/lib/mysqlcppconn/linux/x64\(64\ bit\)/ -lmysqlcppconn"

SOURCES += main.cpp \
    areacoveringalgorithm.cpp \
    arraymap.cpp \
    dimension.cpp \
    route.cpp \
    testcopter.cpp \
    waypoint.cpp \
    databaseconnector.cpp \
    point.cpp \
    point.cpp

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
    point.hpp


#win64:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../deps/lib/mysqlcppconn/windows/x64(64\ bit)/ -lmysqlcppconn
#else:win64:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../deps/lib/mysqlcppconn/windows/x64(64\ bit)/ -lmysqlcppconn


#DEPENDPATH += $$PWD/../../../../deps/incl/mysqlcppconn
