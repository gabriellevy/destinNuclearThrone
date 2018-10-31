#ifndef ARME_H
#define ARME_H

#include "qvector.h"

class Arme
{
public:

    Arme(QString Id, QString Intitule, int NbTirs, float BasePctTouche, int ConsoMunition, int Degats);

    QString m_Id;
    QString m_Intitule;
    int m_NbTirs;
    float m_BasePctTouche;
    int m_ConsoMunition;
    int m_Degats;

    static QVector<Arme*> ARMES;

    static void GenererArmes();
};

#endif // ARME_H
