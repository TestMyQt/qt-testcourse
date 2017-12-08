QT += core testlib
QT -= gui

CONFIG += c++11 console testcase
CONFIG -= app_bundle

win32 {
    CONFIG -= debug_and_release debug_and_release_target
}

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
        test_runner.cpp \
        $$PWD/../src/useful.cpp

HEADERS += \
        test_runner.h \
        $$PWD/../src/useful.h


INCLUDEPATH += $$PWD/../src


