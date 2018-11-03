#include "universnucleaire.h"
#include "D:/boulot/QtProjects/destinLib/perso.h"
#include "ui_aventure.h"
#include "run.h"
#include "arme.h"
#include "mutant.h"

UniversNucleaire::UniversNucleaire(ModeAffichage modeAffichage,
                                   QWidget *parent,
                                   QString premierEvt,
                                   QString premierEffet)
    : Aventure(parent, modeAffichage)
{
    m_Perso = new IPerso(ui->persoWidget);
    m_Histoire = new Run(ui->histoireWidget);
    this->setWindowTitle("Nuclear throne");

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
    Arme::GenererArmes();

    GenererCaracs();

    m_Histoire->GenererPersos();

    m_Histoire->GenererHistoire();

    m_Perso->RafraichirAffichage();
}

void UniversNucleaire::GenererCaracs()
{
    m_Histoire->m_Caracs.append(new Jauge(Run::pv, "PV", 0, 8,8,"", ""));
    m_Histoire->m_Caracs.append(new Carac(Run::arme1, "Arme active", "Revolver", ":/images/armes/Pistol3.png", "", MODE_AFFICHAGE::ma_Img));
    m_Histoire->m_Caracs.append(new Carac(Run::arme2, "Arme secondaire", "", "", "", MODE_AFFICHAGE::ma_Img));

    /// compétences
    {
        m_Histoire->m_Caracs.append(new Carac(Run::back_muscle, "Back Muscle", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::bloodlust, "Bloodlust", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::boiling_veins, "Boiling Veins", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::bolt_marrow, "Bolt Marrow", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::eagle_eyes, "Eagle Eyes", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::euphoria, "Euphoria", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::extra_feet, "Extra Feet", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::gamma_guts, "Gamma Guts", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::hammerhead, "Hammerhead", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::heavy_heart, "Heavy Heart", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::impact_wrists, "Impact Wrists", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::laser_brain, "Laser Brain", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::last_wish, "Last Wish", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::long_arms, "Long Arms", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::lucky_shot, "Lucky Shot", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::open_mind, "Open Mind", "",
                                              "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::patience, "Patience", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::plutonium_hunger, "Plutonium Hunger", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::rabbit_paw, "Rabbit Paw", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::recycle_gland, "Recycle Gland", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::rhino_skin, "Rhino Skin", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::scarier_face, "Scarier Face", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::second_stomach, "Second Stomach", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::sharp_teeth, "Sharp Teeth", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::shotgun_shoulders, "Shotgun Shoulders", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::stress, "Stress", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::strong_spirit, "Strong Spirit", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::throne_butt, "Throne Butt", "", "", "", MODE_AFFICHAGE::ma_Img));
        m_Histoire->m_Caracs.append(new Carac(Run::trigger_fingers, "Trigger Fingers", "", "", "", MODE_AFFICHAGE::ma_Img));

        /// munitions
        m_Histoire->m_Caracs.append(new Carac(Run::balles, "Balles", "96", "", "", MODE_AFFICHAGE::ma_Nombre));
        m_Histoire->m_Caracs.append(new Carac(Run::cartouches, "Cartouches", "0", "", "", MODE_AFFICHAGE::ma_Nombre));
        m_Histoire->m_Caracs.append(new Carac(Run::carreaux, "Carreaux", "0", "", "", MODE_AFFICHAGE::ma_Nombre));
        m_Histoire->m_Caracs.append(new Carac(Run::explosifs, "Explosifs", "0", "", "", MODE_AFFICHAGE::ma_Nombre));
        m_Histoire->m_Caracs.append(new Carac(Run::energie, "Énergie", "0", "", "", MODE_AFFICHAGE::ma_Nombre));
    }
}
