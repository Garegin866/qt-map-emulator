QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

MAP_PATH = ../Map

INCLUDEPATH += $$MAP_PATH

SOURCES +=  tst_testmap.cpp \
    $$MAP_PATH//mainwindow.cpp

HEADERS +=  \
    $$MAP_PATH//mainwindow.h

FORMS +=  \
    $$MAP_PATH//mainwindow.ui
