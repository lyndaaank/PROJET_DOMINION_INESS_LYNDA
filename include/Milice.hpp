#ifndef MILICE_HPP
#define MILICE_HPP

#include<iostream>
#include<string>
#include<vector>
#include "CarteAction.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
class Milice : public CarteAction {

public:

    std::vector<std::string> getDescription() const override;

    Milice();

    void appliquerEffet(Joueur& joueur, Partie& partie) override;

    ~Milice();



};





#endif
