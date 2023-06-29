QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    MeticRegister.h


SOURCES +=  tst_exam_tests.cpp \
    MeticRegister.cpp
