TEMPLATE = app

QT += qml quick sql
CONFIG += c++11

SOURCES += main.cpp \
    Myserver.cpp \
    MyThread.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Myserver.h \
    MyThread.h
