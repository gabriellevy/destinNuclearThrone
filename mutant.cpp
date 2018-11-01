#include "mutant.h"
#include "run.h"

Mutant::Mutant(QWidget *parent) : IPerso(parent)
{

}

void Mutant::GenererPersos()
{
    DPerso mutant;
    mutant.m_Id = "Mutant";
    mutant.m_Nom = "?";
    m_Persos.push_back(mutant);

    DPerso fish;
    fish.m_Id = "fish";
    fish.m_Nom = "Fish";
    fish.m_Description = "Plus de munitions au début et à chaque ramassage\nBonus d'esquive grâce à ses roulades";
    fish.m_ImagePortrait.load(":/images/persos/Fish_icon1.png");
    fish.m_CaracsAAfficher.append(Run::pv);
    fish.m_CaracsAAfficher.append(Run::arme1);
    fish.m_CaracsAAfficher.append(Run::arme2);
    fish.m_CaracsAAfficher.append(Run::balles);
    fish.m_CaracsAAfficher.append(Run::cartouches);
    fish.m_CaracsAAfficher.append(Run::carreaux);
    fish.m_CaracsAAfficher.append(Run::explosifs);
    fish.m_CaracsAAfficher.append(Run::energie);
    fish.m_CaracsAAfficher.append(Run::back_muscle);
    fish.m_CaracsAAfficher.append(Run::bloodlust);
    fish.m_CaracsAAfficher.append(Run::boiling_veins);
    fish.m_CaracsAAfficher.append(Run::bolt_marrow);
    fish.m_CaracsAAfficher.append(Run::eagle_eyes);
    fish.m_CaracsAAfficher.append(Run::euphoria);
    fish.m_CaracsAAfficher.append(Run::extra_feet);
    fish.m_CaracsAAfficher.append(Run::gamma_guts);
    fish.m_CaracsAAfficher.append(Run::hammerhead);
    fish.m_CaracsAAfficher.append(Run::heavy_heart);
    fish.m_CaracsAAfficher.append(Run::impact_wrists);
    fish.m_CaracsAAfficher.append(Run::laser_brain);
    fish.m_CaracsAAfficher.append(Run::last_wish);
    fish.m_CaracsAAfficher.append(Run::long_arms);
    fish.m_CaracsAAfficher.append(Run::lucky_shot);
    fish.m_CaracsAAfficher.append(Run::open_mind);
    fish.m_CaracsAAfficher.append(Run::patience);
    fish.m_CaracsAAfficher.append(Run::plutonium_hunger);
    fish.m_CaracsAAfficher.append(Run::rabbit_paw);
    fish.m_CaracsAAfficher.append(Run::recycle_gland);
    fish.m_CaracsAAfficher.append(Run::rhino_skin);
    fish.m_CaracsAAfficher.append(Run::scarier_face);
    fish.m_CaracsAAfficher.append(Run::second_stomach);
    fish.m_CaracsAAfficher.append(Run::sharp_teeth);
    fish.m_CaracsAAfficher.append(Run::shotgun_shoulders);
    fish.m_CaracsAAfficher.append(Run::stress);
    fish.m_CaracsAAfficher.append(Run::strong_spirit);
    fish.m_CaracsAAfficher.append(Run::throne_butt);
    fish.m_CaracsAAfficher.append(Run::trigger_fingers);
    m_Persos.push_back(fish);

}
