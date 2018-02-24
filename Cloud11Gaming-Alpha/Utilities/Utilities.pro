TEMPLATE = app
CONFIG += console

SOURCES += main.cpp \
    Utility.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Utility.h

