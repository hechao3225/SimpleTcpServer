#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T10:17:28
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer_Test
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myserver.cpp \
    myclient.cpp

HEADERS  += widget.h \
    myserver.h \
    myclient.h

FORMS    += widget.ui
