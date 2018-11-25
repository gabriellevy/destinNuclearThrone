#ifndef ENNEMI_H
#define ENNEMI_H
#include <QString>

class Ennemi
{
public:
    Ennemi();
    Ennemi(QString nom, int m_PV, int m_Degats, int m_NbRads, float m_PourcentageTouche, int portee, QString imgIdle);
    Ennemi(const Ennemi &ennemi);

    QString m_Nom;
    int m_PV;
    int m_Degats;
    int m_Portee;
    int m_NbRads;
    float m_PourcentageTouche;
    QString m_ImgIdle;

    // factory d'ennemis :
    static Ennemi GenerationEnnemi(QString id);

    // id des types d'ennemis
    static QString s_Bandit;
    static QString s_NidAAsticot;
    static QString s_Asticot;
    static QString s_AsticotGeant;
    static QString s_Scorpion;
    static QString s_ScorpionOr;
    static QString s_GrosBandit;
};

#endif // ENNEMI_H
