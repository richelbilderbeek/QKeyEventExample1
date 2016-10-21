QT       += core gui

# C++14
CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    dialog.cpp \
    dialog_test.cpp

HEADERS  += \
    dialog.h \
    dialog_test.h

FORMS    += dialog.ui

# QTest
QT += testlib
