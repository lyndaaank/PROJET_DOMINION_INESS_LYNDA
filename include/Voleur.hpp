
#ifndef __VOLEUR__H
#define __VOLEUR__H

#include "CarteAction.hpp"

class Voleur : public CarteAction{

public :
    Voleur();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
    ~Voleur();
};

#endif
