#ifndef ARME_H
#define ARME_H

#include <QHash>
#include <QVector>
#include "ennemi.h"

enum TypeMunition {
    tm_Balle,
    tm_Cartouche,
    tm_Explosif,
    tm_Energie,
    tm_Carreau
};

class Arme
{
public:

    Arme(QString Id = "", QString Intitule = "", QString CheminImg = "",
         int NbTirs = 1, float BasePctTouche = 0.1f,
         int ConsoMunition = 1, int Degats = 1, TypeMunition typeMunition = tm_Balle);

    QString m_Id;
    QString m_Intitule;
    QString m_CheminImg;
    int m_NbTirs;
    float m_BasePctTouche;
    int m_ConsoMunition;
    int m_Degats;
    TypeMunition m_TypeMunition;

    int AttaqueEnnemis(QVector<Ennemi> &ennemis);

    static QHash<QString, Arme*> ARMES;

    static void GenererArmes();

    static QString revolver;
    static QString fusilapompe;
    static QString arbalete;
};

#endif // ARME_H
