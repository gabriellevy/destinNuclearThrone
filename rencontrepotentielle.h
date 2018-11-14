#ifndef RENCONTREPOTENTIELLE_H
#define RENCONTREPOTENTIELLE_H

#include "generateurennemis.h"
#include <QVector>

enum TypeRencontre {
    tr_Ennemis, // rencontre de base avec un certain nombre d'ennemi
    tr_CoffreMunitions,
    tr_CoffreArmes,
    tr_MultiRencontres
};

/**
 * @brief Système de probabilité servant à calculer les rencontres arrivant à un joueur dans un niveau
 */

class RencontrePotentielle
{
public:
    RencontrePotentielle();

    TypeRencontre m_TypeRencontre;
    float m_Proba = -1;
    QVector<GenerateurEnnemis> m_GenerateursEnnemi = {};
};

#endif // RENCONTREPOTENTIELLE_H
