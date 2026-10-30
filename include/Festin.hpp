#ifndef __FESTIN__H
#define __FESTIN__H

#include "CarteAction.hpp"

class Festin : public CarteAction{

public:

    std::vector<std::string> getDescription() const override;

    Festin();

    void appliquerEffet(Joueur& joueur, Partie& partie) override;

    ~Festin();
};
#endif
