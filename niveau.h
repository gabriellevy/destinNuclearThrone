#ifndef NIVEAU_H
#define NIVEAU_H

#include <QHash>
#include <QVector>
#include "rencontre.h"

class Niveau
{
private:
    // les rencontres qui au final se trouveront réellement dans le niveau. Calculées lors du lancement
    QVector<Rencontre> m_RencontresFinales = {};

public:
    Niveau(QString id, Ouverture ouverture, QString niveauSuivant = "");

    void AjouterRencontrePossibleAvecEnnemis(float proba, int minimum, int maximum, QString ennemiId);

    /**
     * @brief Génère l'intégralité de la rencontre
     * Ajoute les rencontres obligatoires et détermine les rencontres facultatives pour remplir le total des rencontres du niveau
    */
    void CalculRencontres();

    QString m_Id;
    Ouverture m_Ouverture;
    QString m_NiveauSuivant;// id du niveau suivant
    int m_NbRencontres;
    QVector<Rencontre> m_RencontresPossibles = {};
    QVector<Rencontre> m_RencontresObligatoires = {};
    // ouverture de base du niveau, mais peut être surclassé par l'ouverture d'une rencontre particulière

    // "singletons"
    static QHash<QString, Niveau> s_Niveaux;
    static void AjouterNiveau(Niveau niveau);
};

#endif // NIVEAU_H
