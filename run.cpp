#include "run.h"
#include "ui_aventure.h"
#include "niveau.h"
#include "mutant.h"

QString Run::pv = "pv";
QString Run::arme1 = "arme1";
QString Run::arme2 = "arme2";
QString Run::back_muscle = "back_muscle";
QString Run::bloodlust = "bloodlust";
QString Run::boiling_veins = "boiling_veins";
QString Run::bolt_marrow = "bolt_marrow";
QString Run::eagle_eyes = "eagle_eyes";
QString Run::euphoria = "euphoria";
QString Run::extra_feet = "extra_feet";
QString Run::gamma_guts = "gamma_guts";
QString Run::hammerhead = "hammerhead";
QString Run::heavy_heart = "heavy_heart";
QString Run::impact_wrists = "impact_wrists";
QString Run::laser_brain = "laser_brain";
QString Run::last_wish = "last_wish";
QString Run::long_arms = "long_arms";
QString Run::lucky_shot = "lucky_shot";
QString Run::open_mind = "open_mind";
QString Run::patience = "patience";
QString Run::plutonium_hunger = "plutonium_hunger";
QString Run::rabbit_paw = "rabbit_paw";
QString Run::recycle_gland = "recycle_gland";
QString Run::rhino_skin = "rhino_skin";
QString Run::scarier_face = "scarier_face";
QString Run::second_stomach = "second_stomach";
QString Run::sharp_teeth = "sharp_teeth";
QString Run::shotgun_shoulders = "shotgun_shoulders";
QString Run::stress = "stress";
QString Run::strong_spirit = "strong_spirit";
QString Run::throne_butt = "throne_butt";
QString Run::trigger_fingers = "trigger_fingers";
QString Run::balles = "balles";
QString Run::cartouches = "cartouches";
QString Run::carreaux = "carreaux";
QString Run::explosifs = "explosifs";
QString Run::energie = "energie";

Run::Run(QWidget *parent):Histoire(parent)
{
}

Run::~Run()
{
}

QVector<QString> Run::s_Competences = {};
void Run::GenererListeCompetences()
{
    Run::s_Competences = { back_muscle, bloodlust, boiling_veins,
            bolt_marrow, eagle_eyes, euphoria, extra_feet, gamma_guts,
            hammerhead, heavy_heart, impact_wrists, laser_brain,
            last_wish, long_arms, lucky_shot, open_mind, patience,
            plutonium_hunger, rabbit_paw, recycle_gland, rhino_skin,
            scarier_face, second_stomach, sharp_teeth, shotgun_shoulders,
            stress, strong_spirit, throne_butt, trigger_fingers };
}

void Run::GenererHistoire()
{
    m_Themes.append("unclear throne");

    GenererEvtsAccueil();

    GenererNiveaux();
}

Niveau* Run::AjouterNiveau(QString id, QString nom, Ouverture ouverture, int nbRencontres, QString niveau_suivant, QString img, QString musique)
{
    Niveau* evt = new Niveau(id, nom, ouverture, nbRencontres, niveau_suivant);
    m_Evts.push_back(evt);

    // ajouter un niveau ajoute automatiquement ses effets
    Effet* entreeNiveau = evt->AjouterEffetNarration("Début du désert 1-1", img);
    entreeNiveau->m_Son = musique;
    entreeNiveau->AjouterCallback(&Niveau::CalculRencontres, id);

    return evt;
}

void Run::GenererNiveaux()
{
    Niveau* NivDesert11 = AjouterNiveau( Niveau::NivDesert11,
                                         "Désert",
                                         Ouverture::o_ZoneOuverte,
                                         10,
                                         Niveau::NivDesert12,
                                         ":/images/niveau/Desert2.png",
                                         "qrc:/sons/mus1.mp3");
    NivDesert11->AjouterRencontrePossibleAvecEnnemis(1.0f, 1, 10, Ennemi::s_Bandit);
    NivDesert11->AjouterRencontrePossibleAvecEnnemis(0.15f, 1, 1, Ennemi::s_NidAAsticot);
    NivDesert11->AjouterRencontrePossibleAvecEnnemis(0.6f, 1, 1, Ennemi::s_Asticot);
    NivDesert11->AjouterRencontrePossibleAvecEnnemis(0.5f, 1, 1, Ennemi::s_AsticotGeant);
    NivDesert11->AjouterRencontrePossibleAvecEnnemis(0.6f, 1, 3, Ennemi::s_Scorpion);
    NivDesert11->AjouterRencontrePossibleAvecEnnemis(0.01f, 1, 1, Ennemi::s_ScorpionOr);

}

void Run::GenererPersos()
{
    Mutant mutant( "Mutant", "?", "", ":/images/persos/Inconnu.png");
    IPerso::AjouterPersoJouable(mutant);

    Mutant fish( "fish", "Fish", "Plus de munitions au début et à chaque ramassage\nBonus d'esquive grâce à ses roulades", ":/images/persos/Fish_icon1.png");
    IPerso::AjouterPersoJouable(fish);

}

void Run::GenererEvtsAccueil()
{
    Evt* Debut = AjouterEvt("Debut", "Choix de personnage");
    Effet* intro = Debut->AjouterEffetNarration(
                "Choisissez votre personnage.",
                ":/images/niveau/game-development-startups-nt-campfire-gif.gif");
    intro->m_Son = "qrc:/sons/MusiqueIntro1.mp3";
    intro->m_OrientationAffichageChoix = OrientationAffichageChoix::oac_horizontal;
    intro->AjouterChoixGoToEffet("", "selection_fish", ":/images/persos/Fish_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_eyes", ":/images/persos/Eyes_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_melting", ":/images/persos/Melting_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_plante", ":/images/persos/Plant_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_yv", ":/images/persos/Yv_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_steroid", ":/images/persos/Steroids_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_robot", ":/images/persos/Robot_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_poulet", ":/images/persos/Chicken_icon2.png");
    intro->AjouterChoixGoToEffet("", "selection_rebelle", ":/images/persos/Rebel_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_horreur", ":/images/persos/Horror_icon1.png");
    intro->AjouterChoixGoToEffet("", "selection_rogue", ":/images/persos/Rogue_icon1.png");

    // Fish :
    QString description = IPerso::GetPersoInterface()->GetPerso("fish").m_Description;
    Effet* fishPers = Debut->AjouterEffetChangementPerso("fish", description, ":/images/persos/Fish_idle.gif", "selection_fish");
    fishPers->m_GoToEvtId = Niveau::NivDesert11;
}
