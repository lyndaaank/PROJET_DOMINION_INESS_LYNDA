#ifndef BUCHERON_HPP
#define BUCHERON_HPP

#include "CarteAction.hpp"

class Bucheron : public CarteAction {

public:
    Bucheron();

    void appliquerEffet(Joueur& joueur, Partie& partie) override;

    std::vector<std::string> getDescription() const override;
};

#endif
