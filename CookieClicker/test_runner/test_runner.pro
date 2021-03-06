TEMPLATE = app
TARGET = tst_cookieclicker
QT += quick core testlib
CONFIG += c++11 warn_on qmltestcase
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += tst_cookieclicker.cpp

RESOURCES += \
        $$PWD/../src/qml.qrc

INCLUDEPATH += $$PWD/../src

# Additional import path used to resolve QML modules in Qt Creator's code model
QML2_IMPORT_PATH = $$PWD/../src/qml.qrc

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

OTHER_FILES += \
    tst_cookieclicker.qml \
    CookieClickerTest.qml
