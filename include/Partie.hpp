#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>
#include<string>

#include "Joueur.hpp"
#include "Reserve.hpp"

class Carte;

class Partie{

private:

    std::vector<Joueur> m_joueurs;
    int m_joueurCourant;
    Reserve m_reserve;
    std::vector<Carte*> m_rebut;
//les adresses de toutes les cartes ici 
    std::vector<Carte*> m_toutesLesCartes;
    bool m_modeRapide;
    std::vector<std::string> m_historique;

public:

    Partie();
//pour eviter la copie de partie sinon dega niveau de la destruction de scarte et creation !
    Partie(const Partie&) = delete;
    Partie& operator=(const Partie&) = delete;


    void afficherBienvenue() const;
    void afficherDebutTour() const; 
    void afficherPhase(const std::string& nom) const;
    void afficherCompteurs() const;

    void initialiser();//prépare tous reserve joueur deck et le mode
    int verifSaisieNumero();

    void ajouterHistorique(const std::string& evenement);
    void afficherHistorique() const;

    void jouer();//lance partie
    void jouerTour();//tour joueur courant

    void acheterCarte(const std::string& nom);//ici lachat car coordonne deja joueur et partie ! 
    void mettreAurebut(Carte* carte);//elle detruit pas la carte elle reste dans la zone de jeu

    void phaseAction();
    void phaseAchat();
    void phaseAjustement();

    void changerJoueur();

    bool estTerminee();
    void determinerGagnant();


    std::vector<Joueur>& getJoueurs();
    Reserve& getReserve();

    ~Partie();

};

#endif

