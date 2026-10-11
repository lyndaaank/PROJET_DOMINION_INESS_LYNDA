
#ifndef __SORCIERE__H
#define __SORCIERE__H

#include "CarteAction.hpp"

class Sorciere : public CarteAction{

public :
    Sorciere();
    void appliquerEffet(Partie& partie, Joueur& joueur) override;
    ~Sorciere();
};

#endif
