
#ifndef __CARTEACT__H
#define __CARTEACT__H
#include <string>
#include "Carte.hpp"
class Partie;
class Joueur;

class CarteAction : public Carte{

private :
    bool m_Attaque;
    bool m_Reaction;

public :
    virtual void appliquerEffet(Joueur& joueur, Partie& partie) = 0;
    CarteAction(bool attaque, bool reaction,const std :: string& nom, int cout);
    bool getAttaque() const;
    bool getReaction() const;
    ~CarteAction();
};

#endif

