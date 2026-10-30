#ifndef LABORATOIRE_HPP
#define LABORATOIRE_HPP

#include"CarteAction.hpp"

class Laboratoire : public CarteAction {

public: 
    Laboratoire();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;
    std::vector<std::string> getDescription() const override;

};




#endif
