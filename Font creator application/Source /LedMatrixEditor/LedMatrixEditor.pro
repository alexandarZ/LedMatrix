#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T12:40:45
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LedMatrixEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrix.cpp

HEADERS  += mainwindow.h \
    matrix.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
