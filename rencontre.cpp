#include "rencontre.h"

Rencontre::Rencontre(QString id,
                     QString imgPath,
                     QWidget *parent)
    :Effet( id, "", imgPath, parent)
{

}


void Rencontre::GenerationEnnemis(RencontrePotentielle rencontrePossible)
{
    switch (m_TypeRencontre) {
    case TypeRencontre::tr_Ennemis :
    {
        // déterminer le générateur d'ennemis à appliquer :
        int indexGenEennemi = rand()%rencontrePossible.m_GenerateursEnnemi.size();
        GenerateurEnnemis gene = rencontrePossible.m_GenerateursEnnemi.at(indexGenEennemi);

        // générer les ennemis en focntion de ce générateur :
        int nbEnnemis = 1;
        if ( gene.m_Minimum != gene.m_Maximum )
            nbEnnemis = rand() % (gene.m_Maximum - gene.m_Minimum) + gene.m_Minimum;

        for (int i = 0; i<nbEnnemis ; i++)
        {
            m_Ennemis.push_back(Ennemi::GenerationEnnemi(gene.m_IdEnnemi));
        }

        this->m_Text = m_Ennemis.at(0).m_Nom + " (" + QString::number(nbEnnemis) + ")";
    }break;
    default: {

    }break;

    }
}
