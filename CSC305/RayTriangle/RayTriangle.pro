#-------------------------------------------------
#
# Project created by QtCreator 2013-03-20T12:25:32
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = RayTriangle
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderwidget.cpp \
    raytrianle.cpp \
    supporting_files/s_openglerror.cpp \
    supporting_files/s_core3_2_context.cpp

HEADERS  += mainwindow.h \
    renderwidget.h \
    raytrianle.h \
    supporting_files/s_openglerror.h \
    supporting_files/s_core3_2_context.h

FORMS    += mainwindow.ui

mac {
     OBJECTIVE_SOURCES  +=
     LIBS += -framework Foundation -framework Cocoa
}
else {
    INCLUDEPATH += external/include
        SOURCES += external/src/glew.c
}

OTHER_FILES += \
    supporting_files/s_core_profile_attributes.mm
