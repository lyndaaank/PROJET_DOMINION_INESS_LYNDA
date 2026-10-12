#ifndef CHAPELLE_HPP
#define CHAPELLE_HPP

#include"CarteAction.hpp"

class Chapelle : public CarteAction {

public: 
    Chapelle ();
    void appliquerEffet(Joueur& joueur, Partie& partie) override;

};




#endif
