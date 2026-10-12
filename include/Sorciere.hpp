
#ifndef __SORCIERE__H
#define __SORCIERE__H

#include "CarteAction.hpp"

class Sorciere : public CarteAction{

public :
    Sorciere();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
    ~Sorciere();
};

#endif
