#ifndef PARTIE_HPP
#define PARTIE_HPP

#include<vector>

#include"Joueur.hpp"
#include "Reserve.hpp"

class Carte;

class Partie{

private:

    std::vector<Joueur> m_joueurs;
    int m_joueurCourant;
    Reserve m_reserve;
    std::vector<Carte*> m_rebut;
    bool m_modeRapide; 

public:

    Partie();

    void initialiser();//prépare tous reserve joueur deck et le mode 

    void joueur();//lance partie
    void joueurTour();//tour joueur courant 

    void acheterCarte(Carte* carte);
    void mettreAurebut(Carte* carte);//elle detruit pas la carte elle reste dans la zone de jeu 

    void phaseAction();
    void phaseAchat();
    void phaseAjustement();

    void changerJoueur();

    bool estTerminee();
    void determinerGagnant();

    ~Partie();

};


#endif
