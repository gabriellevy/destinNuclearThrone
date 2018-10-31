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
    //static QString competence_armement;
    //static QString competence_vehicule;

private:
    //void GenererEvtsAccueil();

};

#endif // RUN_H
