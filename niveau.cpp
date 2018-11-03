#include "niveau.h"

QHash<QString, Niveau> Niveau::s_Niveaux = {};

Niveau::Niveau(QString id, Ouverture ouverture, QString niveauSuivant)
    :m_Id(id), m_Ouverture(ouverture), m_NiveauSuivant(niveauSuivant)
{
    Niveau::s_Niveaux.insert(m_Id, *this);

    Niveau::AjouterNiveau( *this);
}

void Niveau::AjouterRencontrePossibleAvecEnnemis(float proba, int minimum, int maximum, QString ennemiId)
{
    Rencontre rencontre;
    rencontre.m_TypeRencontre = tr_Ennemis;
    rencontre.m_Proba = proba;
    rencontre.m_GenerateursEnnemi.push_back(GenerateurEnnemis(ennemiId, minimum, maximum));
    m_RencontresPossibles.push_back(rencontre);
}

void Niveau::CalculRencontres()
{
    foreach (const Rencontre f_Rencontre, m_RencontresObligatoires)
        m_RencontresFinales.push_back(f_Rencontre);

    float totalProba = 0;
    foreach (const Rencontre f_Rencontre, m_RencontresPossibles)
    {
        totalProba += f_Rencontre.m_Proba;
    }

    while ( m_RencontresFinales.size() < m_NbRencontres)
    {
        float proba = rand() * totalProba;
        float totalCourant = 0;
        foreach (const Rencontre f_Rencontre, m_RencontresPossibles)
        {
            totalCourant += f_Rencontre.m_Proba;
            if ( proba < totalCourant)
            {
                // nombre déterminé et génération de rencontred ajoutée
                m_RencontresFinales.push_back(Rencontre(f_Rencontre));
                break;
            }
        }
    }
}

void Niveau::AjouterNiveau(Niveau niveau)
{
    // c'est ici qu'on remplit les niveaux de leurs rencontres :
    if (niveau.m_Id == "desert1-1")
    {

    } else {
        Q_ASSERT_X(false, "AjouterNiveau", (QString("Ce niveau est impossible à générer : " + niveau.m_Id)).toStdString().c_str() );
    }


    Niveau::s_Niveaux.insert(niveau.m_Id, niveau);
}
