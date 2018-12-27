#include <QApplication>
#include "universnucleaire.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QWidget {background-image: url(qrc:/images/fond.jpg) }");

    UniversNucleaire* av = new UniversNucleaire(ModeAffichage::ema_Jeu);
    av->show();


    return a.exec();
}
