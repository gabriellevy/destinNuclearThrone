#include "mutant.h"

Mutant::Mutant(QWidget *parent) : IPerso(parent)
{

}

void Mutant::GenererPersos()
{
    DPerso mutant;
    mutant.m_Id = "Mutant";
    mutant.m_Nom = "Mutant";
    /*mutant.m_ImagePortrait.load(":/mekano.jpg");
    mutant.m_CaracsAAfficher.append("competence_armement");*/
    m_Persos.push_back(mutant);
}
