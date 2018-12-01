#ifndef RENCONTRE_H
#define RENCONTRE_H

#include <QVector>
#include "ennemi.h"
#include "../destinLib/effet.h"
#include "rencontrepotentielle.h"

// est-ce qu'une zone ou un niveau est plutôt encaissée ou plutôt ouverte ?
enum Ouverture {
    o_Corridor,
    o_PetiteSalle,
    o_ZoneOuverte,
    o_Indifferent // utile pour les rencontres dont l'ouverture dépend de la zone où elles se trouvent
};

class Niveau;

/**
 * @brief Forme d'effet arrivant dans les niveaux semi aléatoirement
 */
class Rencontre : public Effet
{
public:
    Rencontre(Niveau* niveau,
              QString id,
              QString imgPath = "",
              QWidget *parent = nullptr);

    QVector<Ennemi> m_Ennemis = {};

    // génère le contenu non fixe de la rencontre, par exemple le nombre semi aléatoire d'ennemis est calculé
    void GenerationEnnemis(RencontrePotentielle rencontrePossible);

    /**
     * @brief renvoie la liste des ennemis présents dans la rencontre
     */
    const QString TexteDescriptif();

    TypeRencontre m_TypeRencontre;
    // ouverture de base du niveau, mais peut être surclassé par l'ouverture d'une rencontre particulière
    Ouverture m_Ouverture;

    void CalculRound(QVector<QString> idNiveauEtidEffet);

private:
    Niveau* m_Niveau;
};

#endif // RENCONTRE_H
