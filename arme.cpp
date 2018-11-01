#include "arme.h"

 QVector<Arme*> Arme::ARMES;

Arme::Arme(QString Id, QString Intitule, QString CheminImg,
           int NbTirs, float BasePctTouche, int ConsoMunition, int Degats)
 : m_Id( Id), m_Intitule(Intitule), m_CheminImg(CheminImg), m_NbTirs(NbTirs),
   m_BasePctTouche(BasePctTouche), m_ConsoMunition(ConsoMunition),
   m_Degats(Degats)
{

}

void Arme::GenererArmes()
{
    ARMES.append( new Arme("revolver", "Révolver", ":/images/armes/Pistol3.png", 1, 0.6f, 1, 3));
    ARMES.append( new Arme("fusilapompe", "Fusil à pompe", ":/images/armes/Shotgun3.png", 1, 0.9f, 1, 4));
    ARMES.append( new Arme("arbalete", "Arbalète", ":/images/armes/Crossbow3.png", 1, 0.7f, 1, 10));
}
