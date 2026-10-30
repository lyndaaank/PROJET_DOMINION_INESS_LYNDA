#ifndef ESPION_HPP
#define ESPION_HPP

#include "CarteAction.hpp"

class Espion : public CarteAction {

public:
    Espion();

    void appliquerEffet(Joueur& joueur, Partie& partie) override;

    std::vector<std::string> getDescription() const override;
    ~Espion();
};

#endif
