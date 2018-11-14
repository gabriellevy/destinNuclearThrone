#ifndef MUTANT_H
#define MUTANT_H

#include "../destinLib/perso.h"

class Mutant : public DPerso
{
public:
    Mutant(QString id, QString nom, QString description, QString imagePortrait);

    ~Mutant();
};

#endif // MUTANT_H
