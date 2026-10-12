
#ifndef __DOUVES__H
#define __DOUVES__H

#include "CarteAction.hpp"

class Douves : public CarteAction{

public :
    Douves();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
    ~Douves();
};

#endif
