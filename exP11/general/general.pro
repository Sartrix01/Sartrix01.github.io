TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17

SOURCES = \
    Systeme.cc \
    particule.cc \
    vecteur3d.cc

HEADERS += \
    Argon.h \
    Helium.h \
    Neon.h \
    enceinte.h \
    dessinable.h \
    generateuraleatoire.h \
    particule.h \
    support_a_dessin.h \
    systeme.h \
    trainee.h \
    vecteur3d.h
