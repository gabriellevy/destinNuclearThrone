#ifndef RUN_H
#define RUN_H

#include <QWidget>
#include "D:/boulot/QtProjects/destinLib/histoire.h"

class Run : public Histoire
{
    Q_OBJECT

public:
    explicit Run(QWidget *parent = nullptr);
    ~Run();

    virtual void GenererHistoire();

    // callbacks spécifiques :
    //static void TempPasse(QString nbJoursStr);
    static QString pv;
    static QString arme1;
    static QString arme2;

    // nom de toutes les mutations (passées à 1 quand le eprsonnage les a)
    static QString back_muscle;
    static QString bloodlust;
    static QString boiling_veins;
    static QString bolt_marrow;
    static QString eagle_eyes;
    static QString euphoria;
    static QString extra_feet;
    static QString gamma_guts;
    static QString hammerhead;
    static QString heavy_heart;
    static QString impact_wrists;
    static QString laser_brain;
    static QString last_wish;
    static QString long_arms;
    static QString lucky_shot;
    static QString open_mind;
    static QString patience;
    static QString plutonium_hunger;
    static QString rabbit_paw;
    static QString recycle_gland;
    static QString rhino_skin;
    static QString scarier_face;
    static QString second_stomach;
    static QString sharp_teeth;
    static QString shotgun_shoulders;
    static QString stress;
    static QString strong_spirit;
    static QString throne_butt;
    static QString trigger_fingers;
    static QVector<QString> s_Competences;
    static void GenererListeCompetences();

    static QString balles;
    static QString cartouches;
    static QString carreaux;
    static QString explosifs;
    static QString energie;

private:
    void GenererNiveaux();
    void GenererEvtsAccueil();
    virtual void GenererPersos();

};

#endif // RUN_H
