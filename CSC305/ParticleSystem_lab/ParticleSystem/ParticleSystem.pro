#-------------------------------------------------
#
# Project created by QtCreator 2013-02-23T22:07:55
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = ParticleSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    particlesystem.cpp \
    renderwidget.cpp \
    supporting_files/s_core3_2_context.cpp \
    supporting_files/s_program.cpp \
    supporting_files/s_shader.cpp \
    supporting_files/s_openglerror.cpp \
    supporting_files/s_parameter.cpp \
    supporting_files/s_stream.cpp \
    supporting_files/s_tokenizer.cpp

HEADERS  += mainwindow.h \
    particlesystem.h \
    renderwidget.h \
    supporting_files/s_core3_2_context.h \
    supporting_files/s_program.h \
    supporting_files/s_parameter.h \
    supporting_files/s_openglerror.h \
    supporting_files/s_shader.h \
    supporting_files/s_stream.h \
    supporting_files/s_tokenizer.h

FORMS    += mainwindow.ui

mac {
     OBJECTIVE_SOURCES  += supporting_files/s_core_profile_attributes.mm
     LIBS += -framework Foundation -framework Cocoa
}
else {
    INCLUDEPATH += external/include
        SOURCES += external/src/glew.c
}

OTHER_FILES += \
    particle_v.vert \
    particle_f.frag
