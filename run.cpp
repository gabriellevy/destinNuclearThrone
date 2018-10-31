#include "run.h"
#include "ui_aventure.h"

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
}

void Run::GenererEvtsAccueil()
{
    Evt* Debut = AjouterEvt("Debut", "Choix de personnage");
    Effet* intro = Debut->AjouterEffetNarration("Choisissez votre personnage.", ":/images/niveau/game-development-startups-nt-campfire-gif.gif");
    //intro->m_GoToEvtId = "RandomJournalier";

}
