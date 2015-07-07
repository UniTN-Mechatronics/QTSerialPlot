#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T14:12:29
#
#-------------------------------------------------

QT       += core gui widgets serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serial_plotter_1
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ../../../../../../qcustomplot/qcustomplot.cpp

HEADERS  += widget.h \
    ../../../../../../qcustomplot/qcustomplot.h

FORMS    += widget.ui
