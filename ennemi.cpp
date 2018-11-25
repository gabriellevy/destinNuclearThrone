#include "ennemi.h"

QString Ennemi::s_Bandit = "bandit";
QString Ennemi::s_NidAAsticot = "nid_a_asticot";
QString Ennemi::s_Asticot = "asticot";
QString Ennemi::s_AsticotGeant = "asticot_geant";
QString Ennemi::s_Scorpion = "scorpion";
QString Ennemi::s_ScorpionOr = "scorpion_geant";
QString Ennemi::s_GrosBandit = "gros_bandit";

Ennemi::Ennemi(QString nom, int pv, int degats, int nbRads, float pourcentage, int portee, QString imgIdle)
    :m_Nom(nom), m_PV(pv), m_Degats(degats), m_NbRads(nbRads), m_PourcentageTouche(pourcentage), m_Portee(portee), m_ImgIdle(imgIdle)
{

}

Ennemi::Ennemi()
{
    m_Nom = "Inconnu";
    m_PV = 1;
    m_Degats = 1;
    m_NbRads = 1;
    m_PourcentageTouche = 0.1f;
    m_ImgIdle = "";
}

Ennemi::Ennemi(const Ennemi& ennemi)
{
    m_Nom = ennemi.m_Nom;
    m_PV = ennemi.m_PV;
    m_Degats = ennemi.m_Degats;
    m_NbRads = ennemi.m_NbRads;
    m_ImgIdle = ennemi.m_ImgIdle;
    m_PourcentageTouche = ennemi.m_PourcentageTouche;
}

Ennemi Ennemi::GenerationEnnemi(QString id)
{
    if ( id == Ennemi::s_Bandit)
    {
        return Ennemi( "Bandit", 4, 3, 2, 0.003f, 2, ":/images/ennemis/Bandit_idle.gif");
    }
    else if ( id == Ennemi::s_Asticot)
    {
        return Ennemi( "Asticot", 2, 1, 1, 0.02f, 0, ":/images/ennemis/Maggot_walk.gif");
    }
    else if ( id == Ennemi::s_AsticotGeant)
    {
        return Ennemi( "Asticot géant", 22, 1, 10, 0.02f, 0, ":/images/ennemis/Bigmaggot_walk.gif");
    }
    else if ( id == Ennemi::s_NidAAsticot)
    {
        return Ennemi( "Nid à asticot", 12, 0, 5, 0.0f, 0, ":/images/ennemis/Spawner_idle.gif");
    }
    else if ( id == Ennemi::s_Scorpion)
    {
        return Ennemi( "Scorpion", 15, 2, 10, 0.03f, 1, ":/images/ennemis/Scorpion_idle.gif");
    }
    else if ( id == Ennemi::s_ScorpionOr)
    {
        return Ennemi( "Scorpion d'or", 40, 2, 30, 0.1f, 1, ":/images/ennemis/Goldscorpion_idle.gif");
    }
    else if ( id == Ennemi::s_GrosBandit)
    {
        return Ennemi( "Gros bandit", 100, 3, 30, 0.15f, 2, ":/images/ennemis/Bigbandit_idle.gif");
    }

    Q_ASSERT_X(false, "GenerationEnnemi", QString("Création d'ennemi impossible car id non reconnu : " + id).toStdString().c_str());
    return Ennemi("Inconnu", 4, 3, 2, 0.003, 0, "");
}
