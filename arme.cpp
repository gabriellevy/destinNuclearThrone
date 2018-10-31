#include "arme.h"

 QVector<Arme*> Arme::ARMES;

Arme::Arme(QString Id, QString Intitule, int NbTirs, float BasePctTouche, int ConsoMunition, int Degats)
 : m_Id( Id), m_Intitule(Intitule), m_NbTirs(NbTirs),
   m_BasePctTouche(BasePctTouche), m_ConsoMunition(ConsoMunition), m_Degats(Degats)
{

}

void Arme::GenererArmes()
{
    ARMES.append(
      new Arme("revolver", "Révolver", 1, 0.8f, 1, 3));
}
