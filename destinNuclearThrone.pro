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

SOURCES += \
        main.cpp \
    D:/boulot/QtProjects/destinLib/aventure.cpp \
    D:/boulot/QtProjects/destinLib/carac.cpp \
    D:/boulot/QtProjects/destinLib/choix.cpp \
    D:/boulot/QtProjects/destinLib/condition.cpp \
    D:/boulot/QtProjects/destinLib/effet.cpp \
    D:/boulot/QtProjects/destinLib/evt.cpp \
    D:/boulot/QtProjects/destinLib/glisseur.cpp \
    D:/boulot/QtProjects/destinLib/histoire.cpp \
    D:/boulot/QtProjects/destinLib/noeud.cpp \
    D:/boulot/QtProjects/destinLib/perso.cpp \
    D:/boulot/QtProjects/destinLib/setcarac.cpp \
    D:/boulot/QtProjects/destinLib/evtaleatoire.cpp \
    aspectratiolabel.cpp \
    run.cpp \
    mutant.cpp \
    universnucleaire.cpp \
    arme.cpp \
    niveau.cpp \
    rencontre.cpp \
    ennemi.cpp \
    generateurennemis.cpp

HEADERS += \
    D:/boulot/QtProjects/destinLib/aventure.h \
    D:/boulot/QtProjects/destinLib/carac.h \
    D:/boulot/QtProjects/destinLib/choix.h \
    D:/boulot/QtProjects/destinLib/condition.h \
    D:/boulot/QtProjects/destinLib/effet.h \
    D:/boulot/QtProjects/destinLib/evt.h \
    D:/boulot/QtProjects/destinLib/glisseur.h \
    D:/boulot/QtProjects/destinLib/histoire.h \
    D:/boulot/QtProjects/destinLib/noeud.h \
    D:/boulot/QtProjects/destinLib/perso.h \
    D:/boulot/QtProjects/destinLib/setcarac.h \
    D:/boulot/QtProjects/destinLib/evtaleatoire.h \
    aspectratiolabel.h \
    run.h \
    mutant.h \
    universnucleaire.h \
    arme.h \
    niveau.h \
    rencontre.h \
    ennemi.h \
    generateurennemis.h

FORMS += \
    D:/boulot/QtProjects/destinLib/aventure.ui \
    D:/boulot/QtProjects/destinLib/carac.ui \
    D:/boulot/QtProjects/destinLib/choix.ui \
    D:/boulot/QtProjects/destinLib/effet.ui \
    D:/boulot/QtProjects/destinLib/evt.ui \
    D:/boulot/QtProjects/destinLib/histoire.ui \
    D:/boulot/QtProjects/destinLib/noeud.ui \
    D:/boulot/QtProjects/destinLib/perso.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    nuclearthrone.qrc

DISTFILES += \
    images/persos/Fish_idle.gif
