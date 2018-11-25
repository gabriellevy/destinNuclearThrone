#include "rencontre.h"
#include "niveau.h"

Rencontre::Rencontre(QString id,
                     QString imgPath,
                     QWidget *parent)
    :Effet( id, "", imgPath, parent)
{

}


void Rencontre::GenerationEnnemis(RencontrePotentielle rencontrePossible)
{
    switch (m_TypeRencontre) {
    case TypeRencontre::tr_Ennemis :
    {
        // déterminer le générateur d'ennemis à appliquer :
        int indexGenEennemi = rand()%rencontrePossible.m_GenerateursEnnemi.size();
        GenerateurEnnemis gene = rencontrePossible.m_GenerateursEnnemi.at(indexGenEennemi);

        // générer les ennemis en focntion de ce générateur :
        int nbEnnemis = 1;
        if ( gene.m_Minimum != gene.m_Maximum )
            nbEnnemis = rand() % (gene.m_Maximum - gene.m_Minimum) + gene.m_Minimum;

        for (int i = 0; i<nbEnnemis ; i++)
        {
            m_Ennemis.push_back(Ennemi::GenerationEnnemi(gene.m_IdEnnemi));
        }

        this->m_Text = m_Ennemis.at(0).m_Nom + " (" + QString::number(nbEnnemis) + ")";
        if ( m_Ennemis.at(0).m_ImgIdle != "" )
            this->ChargerImage(m_Ennemis.at(0).m_ImgIdle);
    }break;
    default: {

    }break;

    }
}

void Rencontre::CalculRound(QVector<QString> idNiveau_idRencontre_idEffet)
{
    Q_ASSERT_X(idNiveau_idRencontre_idEffet.size() == 3, "Rencontre::CalculRound", "Pas le bon nomber d'argument à la fonction runtime CalclRound");
    Niveau* niveau = Niveau::s_Niveaux[idNiveau_idRencontre_idEffet[0]];
    Rencontre* rencontre = static_cast<Rencontre*>(niveau->TrouverEffet(idNiveau_idRencontre_idEffet[1]));
    Effet* effetCourant = niveau->TrouverEffet(idNiveau_idRencontre_idEffet[2]);

    // détermination de si un nouveau round est nécessaire. Sinon cet appel de fonction est inutile : on laisse le goto amener à la rencontre suivante
    if (rencontre->m_Ennemis.size() > 0 )
    {
        // attaques du joueur


        // attaques des ennemis


        rencontre->m_Ennemis.pop_back();

        // génération d'un nouvel effet où tout cela sera affiché
        QString text = "Tous les ennemis sont éliminés";
        QString imgPath = "";
        if ( rencontre->m_Ennemis.size() > 0)
        {
            text = "ennemi éliminé, mais il reste " + rencontre->TexteDescriptif();
            imgPath = rencontre->m_Ennemis[0].m_ImgIdle;
        }
        Effet* effetRound = niveau->AjouterEffetNarration(text, imgPath);

        // et liens d'enclenchement entre ce nouvel effet et le précédent, puis relancement du prochain round
        effetRound->m_Id = "round" + QString::number(niveau->m_Effets.size());
        QString oldGoToNextRencontre = effetCourant->m_GoToEffetId;
        effetCourant->m_GoToEffetId = effetRound->m_Id;
        effetRound->m_GoToEffetId =oldGoToNextRencontre;
        effetRound->AjouterCallback(&Rencontre::CalculRound,
            {idNiveau_idRencontre_idEffet[0], idNiveau_idRencontre_idEffet[1], effetRound->m_Id});

    }



}


const QString Rencontre::TexteDescriptif()
{
    QHash<QString, int> typeEnnemis;

    foreach ( const Ennemi f_Ennemi, m_Ennemis)
    {
        if (typeEnnemis.contains(f_Ennemi.m_Nom))
                typeEnnemis[f_Ennemi.m_Nom] = (typeEnnemis[f_Ennemi.m_Nom]+1);
        else typeEnnemis[f_Ennemi.m_Nom] = 1;
    }

    QString text = "";
    int compte = 0;
    foreach (QString key, typeEnnemis.keys())
    {
        if ( compte > 0 )
            text += ", ";
        text += QString::number(typeEnnemis[key]) + " " + key + (QString::number(typeEnnemis[key]) > 1 ? "s":"");
        compte++;
    }

    return text;
}
