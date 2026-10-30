#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include<string>
#include<vector>

class Partie;
#include "Carte.hpp"


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

    int m_nombreTours;
        
    public : 
    
    Joueur(const std::string& nom);

    void piocher(int n);

    void ajouterActions(int n);
    void ajouterAchats(int n);
    void ajouterPieces(int n);
    void reinitialiserTour();

    void jouerAction(Carte* carte, Partie& partie);
    void jouerTresor(Carte* carte);
    
    void recevoir(Carte* carte);
    void defausser(Carte* carte);
    int getNombreCartesMain() const;
    void melanger();
    void ajuster(Partie* partie = nullptr);

    int calculerScore() const;            
    
    void ajouterAuDeck(Carte* carte);

    int getAchats() const;
    int getActions() const;
    int getPieces() const;
    
    Carte* getCarteMain(int numero) const;
    std:: string getNomJoueur() const ;
    bool aCarte(TypeCarte type) const;

    void afficher_main()const;

    int getNombreTours() const;
    void ajouterTour();

    int getNombreTotalCartes() const;
    
    bool retirerCarteMain(Carte* carte);
    bool retirerCarteJouee(Carte* carte);

    bool peutSeDefendre() const;
    std::vector<Carte*> revelerCarte(int n);
    void afficherStatistiques() const;
    

};

#endif

