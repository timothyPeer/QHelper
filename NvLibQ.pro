#-------------------------------------------------
#
# Project created by QtCreator 2017-07-05T20:37:25
#
#-------------------------------------------------

QT       += core network sql

TARGET = NvLibQ
TEMPLATE = lib
CONFIG += staticlib

# With C++11 support
greaterThan(QT_MAJOR_VERSION, 4){
CONFIG += c++11
} else {
QMAKE_CXXFLAGS += -std=c++0x
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        nvlibq.cpp \
    connectionstringbuilder.cpp \
    modelnvmonitors.cpp \
    modelnvmonitorsprivate.cpp \
    modelnvprofiles.cpp \
    modelNvProfilesPrivate.cpp \
    modelnvschedules.cpp \
    modelnvschedulesprivate.cpp \
    modelnvtables.cpp \
    modelnvtablesprivate.cpp \
    nvmonitorclass.cpp \
    nvprofilesclass.cpp \
    nvschedulesclass.cpp \
    nvtable.cpp \
    nvtablesclass.cpp \
    qclogobject.cpp \
    qloggerwriter.cpp \
    qnvmonitorprofile.cpp \
    qnvprofiles.cpp \
    qNvRepository.cpp \
    qnvstaticclass.cpp \
    qnvtables.cpp \
    qvtexecute.cpp \
    qvtexecutemodel.cpp \
    qvtexecutetablesonly.cpp \
    vtiFields.cpp \
    vtlexecute.cpp \
    qnvtables.cpp \
    dbcheckobj.cpp

HEADERS += \
        nvlibq.h \
    connectionstringbuilder.h \
    modelnvmonitors.h \
    modelnvmonitorsprivate.h \
    modelnvprofiles.h \
    modelNvProfilesPrivate.h \
    modelnvschedules.h \
    modelnvschedulesprivate.h \
    modelnvtables.h \
    modelnvtablesprivate.h \
    nvmonitorclass.h \
    nvprofilesclass.h \
    nvschedulesclass.h \
    nvtable.h \
    nvtablesclass.h \
    qclogobject.h \
    qloggerwriter.h \
    qnvmonitorprofile.h \
    qnvprofiles.h \
    qNvRepository.h \
    qnvstaticclass.h \
    qnvtables.h \
    qRCEnumDef.h \
    qsql_odbc.h \
    qvtexecute.h \
    qvtexecutemodel.h \
    qvtexecutetablesonly.h \
    vtifields.h \
    vtlexecute.h \
    qnvtables.h \
    dbcheckobj.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}


