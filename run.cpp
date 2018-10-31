#include "run.h"
#include "ui_aventure.h"

//QString VieDunMekano::competence_armement = "competence_armement";
//QString VieDunMekano::competence_vehicule = "competence_vehicule";

Run::Run(QWidget *parent):Histoire(parent)
{
}

Run::~Run()
{
}

void Run::GenererHistoire()
{
    //m_Themes.append("warhammer 40000");

    //GenererEvtsAccueil();
}

/*void Run::GenererEvtsAccueil()
{
    Evt* Debut = AjouterEvt("Debut", "Installation d'un mékano");
    Effet* intro = Debut->AjouterEffetNarration("Youpi vous êtes un mékano.");
    //intro->m_GoToEvtId = "RandomJournalier";
    intro->m_GoToEvtId = "UnJourPasse";

}*/
