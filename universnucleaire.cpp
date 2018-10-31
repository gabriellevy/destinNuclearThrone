#include "universnucleaire.h"
#include "D:/boulot/QtProjects/destinLib/perso.h"
#include "ui_aventure.h"
#include "mutant.h"
#include "run.h"

UniversNucleaire::UniversNucleaire(ModeAffichage modeAffichage,
                                   QWidget *parent,
                                   QString premierEvt,
                                   QString premierEffet)
    : Aventure(parent, modeAffichage)
{
    m_Perso = new Mutant(ui->persoWidget);
    m_Histoire = new Run(ui->histoireWidget);
    this->setWindowTitle("Vie d'un Mékano");

    // positionner l'interface
    ui->persoWidget->layout()->addWidget(m_Perso);
    //m_Perso->show();
    ui->histoireWidget->layout()->addWidget(m_Histoire);

    GenererAventure();

    if ( premierEvt != "" )
        m_Histoire->SetCurrentEvtId( premierEvt ) ;
    if ( premierEffet!= "" )
        m_Histoire->SetEffetIndex(m_Histoire->DeterminerIndexEffet(premierEffet) );

    m_EtatPartie = EP_Deroulement;
    LancerEvtEtOuEffetCourant();
}

UniversNucleaire::~UniversNucleaire()
{
}

void UniversNucleaire::GenererAventure()
{
    GenererCaracs();

    (static_cast<Mutant*>(m_Perso))->GenererPersos();

    m_Histoire->GenererHistoire();

    m_Perso->RafraichirAffichage();
}

void UniversNucleaire::GenererCaracs()
{
    /*m_Perso->m_Caracs.append(new Carac(VieDunMekano::competence_armement, "Compétence en armes", "0",
                                       "",
                                       "", MODE_AFFICHAGE::ma_Nombre
                                       ));*/
}
