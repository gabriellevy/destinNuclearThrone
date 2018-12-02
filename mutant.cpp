#include "mutant.h"
#include "run.h"

Mutant::Mutant(QString id, QString nom, QString description, QString imagePortrait)
{
    m_Id = id;
    m_Nom = nom;
    m_Description = description;

    m_ImagePortrait.load(imagePortrait);

    m_CaracsAAfficher.append(Run::pv);
    m_CaracsAAfficher.append(Run::arme1);
    m_CaracsAAfficher.append(Run::arme2);
    m_CaracsAAfficher.append(Run::balles);
    m_CaracsAAfficher.append(Run::cartouches);
    m_CaracsAAfficher.append(Run::carreaux);
    m_CaracsAAfficher.append(Run::explosifs);
    m_CaracsAAfficher.append(Run::energie);
    m_CaracsAAfficher.append(Run::back_muscle);
    m_CaracsAAfficher.append(Run::bloodlust);
    m_CaracsAAfficher.append(Run::boiling_veins);
    m_CaracsAAfficher.append(Run::bolt_marrow);
    m_CaracsAAfficher.append(Run::eagle_eyes);
    m_CaracsAAfficher.append(Run::euphoria);
    m_CaracsAAfficher.append(Run::extra_feet);
    m_CaracsAAfficher.append(Run::gamma_guts);
    m_CaracsAAfficher.append(Run::hammerhead);
    m_CaracsAAfficher.append(Run::heavy_heart);
    m_CaracsAAfficher.append(Run::impact_wrists);
    m_CaracsAAfficher.append(Run::laser_brain);
    m_CaracsAAfficher.append(Run::last_wish);
    m_CaracsAAfficher.append(Run::long_arms);
    m_CaracsAAfficher.append(Run::lucky_shot);
    m_CaracsAAfficher.append(Run::open_mind);
    m_CaracsAAfficher.append(Run::patience);
    m_CaracsAAfficher.append(Run::plutonium_hunger);
    m_CaracsAAfficher.append(Run::rabbit_paw);
    m_CaracsAAfficher.append(Run::recycle_gland);
    m_CaracsAAfficher.append(Run::rhino_skin);
    m_CaracsAAfficher.append(Run::scarier_face);
    m_CaracsAAfficher.append(Run::second_stomach);
    m_CaracsAAfficher.append(Run::sharp_teeth);
    m_CaracsAAfficher.append(Run::shotgun_shoulders);
    m_CaracsAAfficher.append(Run::stress);
    m_CaracsAAfficher.append(Run::strong_spirit);
    m_CaracsAAfficher.append(Run::throne_butt);
    m_CaracsAAfficher.append(Run::trigger_fingers);
}

Mutant::~Mutant()
{

}
