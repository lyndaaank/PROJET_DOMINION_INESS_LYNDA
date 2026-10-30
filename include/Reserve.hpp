#ifndef RESERVE_HPP
#define RESERVE_HPP

#include<string>
#include<map>
#include<vector>

class Carte;

class Reserve {

private :

    std::map<std::string, std::vector<Carte*>> m_pilesCartes;

public :

    void initialiser(bool modeRapide, const std::vector<std::string>& cartesChoisies);
    bool estDisponible(const std::string& nom) const;
    Carte* retirerCarte(const std::string& nom);
    bool conditionFinAtteinte() const; //regrouper le comptage de pile vide et province vide

    Carte* creerCarte(const std::string& nom);

    std::string getNom(int numero) const;
    int getCout(const std::string& nom) const;

//permet à Partie de récupérer les pointeurs de toutes les cartes créées lors de l'initialisation de la réserve
    std::vector<Carte*> getToutesLesCartes() const;

    void afficherCartesSelonCout(int prixMax) const;

    bool existeCarteSelonCout(int prixMax) const;

    void afficherCarteRoyaume(const std::string& nom);
    void afficher_reserve() const;


};

#endif

