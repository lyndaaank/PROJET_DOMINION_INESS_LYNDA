#ifndef RESERVE_HPP
#define RESERVE_HPP

#include<iostream>
#include<string>
#include<map>

class Carte;

class Reserve {

private : 

    std::map<std::string, int> m_pilesCartes;

public : 

    void initialiser(bool modeRapide);
    void afficher() const;//affiche les piles de cartes dispo et la quantité 
    bool estDisponible(const std::string& nom) const;
    Carte* retirerCarte(const std::string& nom); //donc reserve cree les cartes !!
    bool conditionFinAtteinte() const; //regrouper le comptage de pile vide et province vide


};





#endif
