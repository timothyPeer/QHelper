#-------------------------------------------------
#
# Project created by QtCreator 2017-07-05T20:36:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QHelper
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# With C++11 support
greaterThan(QT_MAJOR_VERSION, 4){
CONFIG += c++11
} else {
QMAKE_CXXFLAGS += -std=c++0x
}

SOURCES += \
        main.cpp \
    createnewprofile.cpp \
    helperdelegate.cpp \
    rcqhelper.cpp \
    dialogclass.cpp

HEADERS += \
    createnewprofile.h \
    helperdelegate.hpp \
    rcqhelper.h \
    ../NvLibQ/nvlibq.h \
    ../NvLibQ/qnvtables.h \
    ../NvLibQ/nvtable.h \
    ../NvLibQ/qnvprofiles.h \
    ../NvLibQ/qNvRepository.h \
    ../NvLibQ/connectionStringBuilder.h \
    dialogclass.h

FORMS += \
    createnewprofile.ui \
    rcqhelper.ui \
    selectedProfileDlg.ui \
    dialogclass.ui

#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../NvLibQ/release/ -llibNVLibQ
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../NvLibQ/debug/ -llibNVLibQ

INCLUDEPATH += "../NvLibQ"
DEPENDPATH += "../NvLibQ"

LIBS += "C:/Users/Tim/Projects/MyRcHelper/MyRCHelper/NvLibQ/debug/libNVLibQ.a"
