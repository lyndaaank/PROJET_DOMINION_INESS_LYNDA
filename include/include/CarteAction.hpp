
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
    virtual void appliquerEffet(Partie& partie, Joueur& joueur) = 0;
    CarteAction(bool attaque, bool reaction, std :: string nom, int cout, std :: string type);
    bool getAttaque() const;
    bool getReaction() const;
    ~CarteAction();
};

#endif
