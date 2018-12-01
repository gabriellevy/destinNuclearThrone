#include "niveau.h"
#include <QtMath>

QHash<QString, Niveau*> Niveau::s_Niveaux = {};

QString Niveau::NivDesert11 = "desert1-1";
QString Niveau::NivDesert12 = "desert1-2";
QString Niveau::NivDesert13 = "desert1-3";

Niveau::Niveau(QString id, QString nom, Ouverture ouverture, int nbRencontres, QString niveauSuivant, QWidget *parent)
    :Evt(id, nom, parent), m_Ouverture(ouverture), m_NiveauSuivant(niveauSuivant), m_NbRencontres(nbRencontres)
{
    m_MsChrono = 600;
    Niveau::s_Niveaux.insert(m_Id, this);

    Niveau::AjouterAListeNiveaux(this);
}

void Niveau::AjouterRencontrePossibleAvecEnnemis(float proba, int minimum, int maximum, QString ennemiId)
{
    RencontrePotentielle rencontre;
    rencontre.m_TypeRencontre = tr_Ennemis;
    rencontre.m_Proba = proba;
    rencontre.m_GenerateursEnnemi.push_back(GenerateurEnnemis(ennemiId, minimum, maximum));
    m_RencontresPossibles.push_back(rencontre);
}

void Niveau::CalculRencontres()
{
    foreach (const RencontrePotentielle f_Rencontre, this->m_RencontresObligatoires)
        this->m_RencontresFinales.push_back(RencontrePotentielle(f_Rencontre));

    float totalProba = 0;
    foreach (const RencontrePotentielle f_Rencontre, this->m_RencontresPossibles)
    {
        totalProba += f_Rencontre.m_Proba;
    }

    while ( this->m_RencontresFinales.size() < this->m_NbRencontres)
    {
        float proba = float(rand())/float(RAND_MAX) * totalProba;
        float totalCourant = 0;
        foreach (const RencontrePotentielle f_Rencontre, this->m_RencontresPossibles)
        {
            totalCourant += f_Rencontre.m_Proba;
            if ( proba < totalCourant)
            {
                // nombre déterminé et génération de rencontred ajoutée
                this->m_RencontresFinales.push_back(RencontrePotentielle(f_Rencontre));
                break;
            }
        }
    }

    // conversions des rencontres finales en effets :
    int indexEffet = 0;
    while ( this->m_RencontresFinales.size() > 0 )
    {
        int indexExtrait = qFloor(rand() % this->m_RencontresFinales.size());
        RencontrePotentielle rencontreChoisie = this->m_RencontresFinales.takeAt(indexExtrait);

        this->AjouterRencontreEffet(rencontreChoisie, indexEffet, this->m_RencontresFinales.size() < 1);
        ++indexEffet;
    }

}

Rencontre* Niveau::AjouterRencontreEffet(RencontrePotentielle rencontrePossible, int index, bool derniereRencontre)
{
    QString idRencontre = ("rencontre" + QString::number(index));
    Rencontre* rencontre = new Rencontre(this, idRencontre);
    rencontre->m_TypeRencontre = rencontrePossible.m_TypeRencontre;

    // selon le numéro de la rencontre elle est suivie d'une autre rencontre ou d'un autre niveau
    if ( !derniereRencontre)
    {
        rencontre->m_GoToEffetId = "rencontre" + QString::number(index + 1);
    }
    auto lambda = [&, idRencontre](QVector<QString> params){
        Rencontre* rencontre = static_cast<Rencontre*>(this->TrouverEffet(idRencontre));
        rencontre->CalculRound(params);
    };
    rencontre->AjouterCallback(lambda, {idRencontre});

    this->AjouterEffet(rencontre);

    // génération d'ennemis :
    rencontre->GenerationEnnemis(rencontrePossible);

    return rencontre;
}

void Niveau::AjouterAListeNiveaux(Niveau* niveau)
{
    // c'est ici qu'on remplit les niveaux de leurs rencontres :
    if (niveau->m_Id == "desert1-1")
    {

    } else {
        Q_ASSERT_X(false, "AjouterNiveau", (QString("Ce niveau est impossible à générer : " + niveau->m_Id)).toStdString().c_str() );
    }


    Niveau::s_Niveaux.insert(niveau->m_Id, niveau);
}
