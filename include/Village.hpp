#ifndef VILLAGE_HPP
#define VILLAGE_HPP

#include "CarteAction.hpp"

class Village : public CarteAction {

public:
    Village();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
};

#endif
