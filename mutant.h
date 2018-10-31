#ifndef MUTANT_H
#define MUTANT_H

#include "D:/boulot/QtProjects/destinLib/perso.h"

class Mutant : public IPerso
{
    Q_OBJECT
public:
    explicit Mutant(QWidget *parent = nullptr);

    virtual void GenererPersos();

signals:

public slots:
};

#endif // MUTANT_H
