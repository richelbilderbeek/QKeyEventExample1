QT       += core gui

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
