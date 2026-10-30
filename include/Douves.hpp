
#ifndef __DOUVES__H
#define __DOUVES__H

#include "CarteAction.hpp"

class Douves : public CarteAction{

public :

    std::vector<std::string> getDescription() const override;
    Douves();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
    ~Douves();
};

#endif
