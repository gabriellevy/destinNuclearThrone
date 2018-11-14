#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T22:16:59
#
#-------------------------------------------------

QT       += core gui widgets multimedia

TARGET = destinNuclearThrone
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        main.cpp \
    ../destinLib/aventure.cpp \
    ../destinLib/carac.cpp \
    ../destinLib/choix.cpp \
    ../destinLib/condition.cpp \
    ../destinLib/effet.cpp \
    ../destinLib/evt.cpp \
    ../destinLib/glisseur.cpp \
    ../destinLib/histoire.cpp \
    ../destinLib/noeud.cpp \
    ../destinLib/perso.cpp \
    ../destinLib/setcarac.cpp \
    ../destinLib/evtaleatoire.cpp \
    aspectratiolabel.cpp \
    run.cpp \
    mutant.cpp \
    universnucleaire.cpp \
    arme.cpp \
    niveau.cpp \
    rencontre.cpp \
    ennemi.cpp \
    generateurennemis.cpp \
    rencontrepotentielle.cpp

HEADERS += \
    ../destinLib/aventure.h \
    ../destinLib/carac.h \
    ../destinLib/choix.h \
    ../destinLib/condition.h \
    ../destinLib/effet.h \
    ../destinLib/evt.h \
    ../destinLib/glisseur.h \
    ../destinLib/histoire.h \
    ../destinLib/noeud.h \
    ../destinLib/perso.h \
    ../destinLib/setcarac.h \
    ../destinLib/evtaleatoire.h \
    aspectratiolabel.h \
    run.h \
    mutant.h \
    universnucleaire.h \
    arme.h \
    niveau.h \
    rencontre.h \
    ennemi.h \
    generateurennemis.h \
    rencontrepotentielle.h

FORMS += \
    ../destinLib/aventure.ui \
    ../destinLib/carac.ui \
    ../destinLib/choix.ui \
    ../destinLib/effet.ui \
    ../destinLib/evt.ui \
    ../destinLib/histoire.ui \
    ../destinLib/noeud.ui \
    ../destinLib/perso.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    nuclearthrone.qrc
