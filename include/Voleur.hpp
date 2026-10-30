#ifndef VOLEUR_HPP
#define VOLEUR_HPP

#include "CarteAction.hpp"

class Voleur : public CarteAction {

public:
    Voleur();

    void appliquerEffet(Joueur& joueur, Partie& partie) override;

    std::vector<std::string> getDescription() const override;
};

#endif
