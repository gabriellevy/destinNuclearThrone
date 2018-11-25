#include "arme.h"
#include "run.h"
#include "universnucleaire.h"

QString Arme::revolver = "revolver";
QString Arme::fusilapompe = "fusilapompe";
QString Arme::arbalete = "arbalete";

QHash<QString, Arme*> Arme::ARMES = {};

Arme::Arme(QString Id, QString Intitule, QString CheminImg,
           int NbTirs, float BasePctTouche, int ConsoMunition, int Degats, TypeMunition typeMunition)
 : m_Id( Id), m_Intitule(Intitule), m_CheminImg(CheminImg), m_NbTirs(NbTirs),
   m_BasePctTouche(BasePctTouche), m_ConsoMunition(ConsoMunition),
   m_Degats(Degats), m_TypeMunition(typeMunition)
{

}

int Arme::AttaqueEnnemis(QVector<Ennemi> & ennemis)
{
    int touches = 0;
    QString typeMunition = Run::balles;
    switch (m_TypeMunition) {
    case tm_Balle : typeMunition = Run::balles; break;
    case tm_Carreau : typeMunition = Run::carreaux; break;
    case tm_Cartouche : typeMunition = Run::cartouches; break;
    case tm_Energie : typeMunition = Run::energie; break;
    case tm_Explosif : typeMunition = Run::explosifs; break;
    }

    for (int i =0 ; i < m_NbTirs ; i++)
    {
        if ( Univers::ME->GetHistoire()->GetCaracValue(typeMunition).toInt() >= m_ConsoMunition)
        {
            float proba = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            if ( proba < m_BasePctTouche)
            {
                touches++;
                // touche :
                int indexEnnemiTouche = rand() % (ennemis.size());
                ennemis[indexEnnemiTouche].m_PV -= m_Degats;

                if ( ennemis[indexEnnemiTouche].m_PV < 1)
                {
                    // élimination
                    ennemis.remove(indexEnnemiTouche);
                }
            }

            Univers::ME->GetHistoire()->AppliquerCarac(SetCarac(ModifCaracType::RetireDeCarac, typeMunition, QString::number(m_ConsoMunition)));
        }
        else
        {
            Q_ASSERT_X(true, "Arme::AttaqueEnnemis", "Pas assez de munitions pour tirer : cas non prévu encore");
        }
    }

    return touches;
}

void Arme::GenererArmes()
{
    ARMES[Arme::revolver] = new Arme(Arme::revolver, "Révolver", ":/images/armes/Pistol3.png", 1, 0.6f, 1, 3);
    ARMES[Arme::fusilapompe] = new Arme(Arme::fusilapompe, "Fusil à pompe", ":/images/armes/Shotgun3.png", 1, 0.9f, 1, 4);
    ARMES[Arme::arbalete] = new Arme(Arme::arbalete, "Arbalète", ":/images/armes/Crossbow3.png", 1, 0.7f, 1, 10);
}
