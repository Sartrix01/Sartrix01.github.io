QT += core gui opengl widgets
contains(QT_VERSION, ^6\\..*) {
    QT += openglwidgets console
}
QMAKE_CXXFLAGS += -std=c++17

win32:LIBS += -lopengl32


TARGET = ex_05_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    glsphere.cc \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc

HEADERS += \
    glsphere.h \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/systeme.h

RESOURCES += \
    resource.qrc
