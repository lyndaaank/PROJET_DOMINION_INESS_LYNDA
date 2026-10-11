
#ifndef __FESTIN__H
#define __FESTIN__H

#include "CarteAction.hpp"

class Festin : public CarteAction{

public :
    Festin();
    void appliquerEffet(Partie& partie, Joueur& joueur) override;
    ~Festin();
};

#endif
