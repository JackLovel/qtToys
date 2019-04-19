#-------------------------------------------------
#
# Project created by QtCreator 2019-04-18T17:07:36
#
#-------------------------------------------------

QT += core
QT += gui
QT += widgets
QT += avwidgets

TARGET = MediaPlayer
TEMPLATE = app

CONFIG += link_pkgconfig
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp \
    dbutton.cpp \
    titlebar.cpp

HEADERS  += mainwindow.h \
    dbutton.h \
    titlebar.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
