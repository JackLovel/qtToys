#-------------------------------------------------
#
# Project created by QtCreator 2019-03-11T16:56:52
#
#-------------------------------------------------

QT += widgets
#QT       += core gui
requires(qtConfig(listview))


TARGET = AddressBook
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    addresswidget.cpp \
    newaddresstab.cpp \
    tablemodel.cpp \
    adddialog.cpp

HEADERS  += mainwindow.h \
    addresswidget.h \
    newaddresstab.h \
    tablemodel.h \
    adddialog.h

FORMS    += mainwindow.ui
