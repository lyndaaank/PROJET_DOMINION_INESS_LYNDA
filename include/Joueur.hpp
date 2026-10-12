#ifndef JOUEUR_HPP
#define JOUEUR_HPP

class Carte;
class Partie;

#include<iostream>
#include<string>
#include<vector>

class Joueur {

    private : 

    std::string m_nom;
    std::vector<Carte*> m_deck;
    std::vector<Carte*> m_main;
    std::vector<Carte*> m_defausse;
    std::vector<Carte*> m_cartesJouees;
    int m_actions;
    int m_achats;
    int m_pieces;
        
    public : 
    
    Joueur(const std::string& nom);//pas de destructeur vois pas interet

    void piocher(int n);//du deck

    void ajouterActions(int n);
    void ajouterAchats(int n);
    void ajouterPieces(int n);
    void reinitialiserTour();//mettre actions etc a 0

    void jouerCarte(Carte* carte, Partie& partie);//de la main ou sans  Parte& partie ????
    void defausser(Carte* carte);
    void recevoir(Carte* carte);//de la reserve ou deck
    void melanger();//main + cartejouee vers defausse
    void ajuster();
    int calculerScore() const;

    void reveler(Carte* carte);//à confirmer fonctionnement et signature !!
    
};

#endif




