#ifndef GENERATEURENNEMIS_H
#define GENERATEURENNEMIS_H

#include <QString>

/**
 * @brief Système utilisé pour générer un certain nombre d'ennemis dans une rencontre
 */
class GenerateurEnnemis
{
public:
    GenerateurEnnemis(QString idEnnemi = "", int minimum = 1, int maximum = 1);

    // valeurs servant à générer un nombre d'ennemis compris entre elles
    int m_Minimum;
    int m_Maximum;
    QString m_IdEnnemi;
};

#endif // GENERATEURENNEMIS_H
