#ifndef RENCONTRE_H
#define RENCONTRE_H

#include <QVector>
#include "ennemi.h"
#include "generateurennemis.h"

// est-ce qu'une zone ou un niveau est plutôt encaissée ou plutôt ouverte ?
enum Ouverture {
    o_Corridor,
    o_PetiteSalle,
    o_ZoneOuverte,
    o_Indifferent // utile pour les rencontres dont l'ouverture dépend de la zone où elles se trouvent
};

enum TypeRencontre {
    tr_Ennemis, // rencontre de base avec un certain nombre d'ennemi
    tr_CoffreMunitions,
    tr_CoffreArmes,
    tr_MultiRencontres
};

/**
 * @brief Forme d'événements arrivant dans les niveaux
 */
class Rencontre
{
public:
    Rencontre();

    float m_Proba = -1;

    QVector<Ennemi> m_Ennemis = {};
    QVector<GenerateurEnnemis> m_GenerateursEnnemi = {};

    // génère le contenu non fixe de la rencontre, par exemple le nombre semi aléatoire d'ennemis est calculé
    void LancementRencontre();

    TypeRencontre m_TypeRencontre;
    // ouverture de base du niveau, mais peut être surclassé par l'ouverture d'une rencontre particulière
    Ouverture m_Ouverture;
};

#endif // RENCONTRE_H
