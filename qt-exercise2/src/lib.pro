QT -= gui

TARGET = lib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

win32 {
    CONFIG -= debug_and_release debug_and_release_target
}

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
	useful.cpp

HEADERS += \
	useful.h

