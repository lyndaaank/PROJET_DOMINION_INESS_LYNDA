#ifndef ATELIER_HPP
#define ATELIER_HPP

#include"CarteAction.hpp"

class Atelier : public CarteAction {

public: 
    Atelier();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;

};




#endif
