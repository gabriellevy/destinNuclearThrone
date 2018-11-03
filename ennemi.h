#ifndef ENNEMI_H
#define ENNEMI_H
#include <QString>

class Ennemi
{
public:
    Ennemi(int m_PV, int m_Degats, int m_NbRads, float m_PourcentageTouche);

    int m_PV;
    int m_Degats;
    int m_NbRads;
    float m_PourcentageTouche;

    static Ennemi GenerationEnnemi(QString id);

    // id des types d'ennemis
    static QString s_Bandit;
};

#endif // ENNEMI_H
