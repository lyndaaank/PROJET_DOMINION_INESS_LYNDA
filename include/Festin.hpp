
#ifndef __FESTIN__H
#define __FESTIN__H

#include "CarteAction.hpp"

class Festin : public CarteAction{

public :
    Festin();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
    ~Festin();
};

#endif
