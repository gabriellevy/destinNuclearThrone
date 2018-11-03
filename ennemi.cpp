#include "ennemi.h"

QString Ennemi::s_Bandit = "bandit";

Ennemi::Ennemi(int pv, int degats, int nbRads, float pourcentage)
    :m_PV(pv), m_Degats(degats), m_NbRads(nbRads), m_PourcentageTouche(pourcentage)
{

}

Ennemi Ennemi::GenerationEnnemi(QString id)
{
    if ( id == "bandit")
    {
        return Ennemi(4, 3, 2, 0.003f);
    }

    Q_ASSERT_X(false, "GenerationEnnemi", QString("Création d'ennemi impossible car id non reconnu : " + id).toStdString().c_str());
    return Ennemi(4, 3, 2, 0.003);
}
