#-------------------------------------------------
#
# Project created by QtCreator 2013-04-29T02:58:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/include/qwt6

TARGET = QwtSineWave
TEMPLATE = app

LIBS += -lqwt

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
