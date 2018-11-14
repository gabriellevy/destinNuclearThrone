#ifndef NIVEAU_H
#define NIVEAU_H

#include <QHash>
#include <QVector>
#include "rencontre.h"
#include "../destinLib/aventure.h"
#include "rencontrepotentielle.h"

class Niveau : public Evt
{
private:
    // les rencontres qui au final se trouveront réellement dans le niveau. Calculées lors du lancement
    // elles sont ensuite transformées en Rencontre c'est à dire en effets affichables
    QVector<RencontrePotentielle> m_RencontresFinales = {};

    // "singletons"
    static QHash<QString, Niveau*> s_Niveaux;
    static void AjouterAListeNiveaux(Niveau* niveau);

public:
    static QString NivDesert11;
    static QString NivDesert12;
    static QString NivDesert13;

    Niveau(QString id, QString nom, Ouverture ouverture, int nbRencontres, QString niveauSuivant = "", QWidget *parent = nullptr);

    void AjouterRencontrePossibleAvecEnnemis(float proba, int minimum, int maximum, QString ennemiId);

    Rencontre* AjouterRencontreEffet(RencontrePotentielle rencontrePossible, int index);

    /**
     * @brief Génère l'intégralité de la rencontre
     * Ajoute les rencontres obligatoires et détermine les rencontres facultatives pour remplir le total des rencontres du niveau
    */
    static void CalculRencontres(QString aQuoiCaSert);

    Ouverture m_Ouverture;
    QString m_NiveauSuivant;// id du niveau suivant
    int m_NbRencontres;
    QVector<RencontrePotentielle> m_RencontresPossibles = {};
    QVector<RencontrePotentielle> m_RencontresObligatoires = {};
    // ouverture de base du niveau, mais peut être surclassé par l'ouverture d'une rencontre particulière

};

#endif // NIVEAU_H
