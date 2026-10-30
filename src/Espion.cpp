
#include "Espion.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"

#include <iostream>
#include <string>
#include <vector>

// Constructeur
Espion::Espion()
    : CarteAction(true, false, "Espion", 4)
{
}

// Effet de la carte Espion
void Espion::appliquerEffet(Joueur& joueur, Partie& partie){

    // Le joueur pioche une carte
    joueur.piocher(1);

    // Le joueur gagne une action supplementaire
    joueur.ajouterActions(1);

    // Recuperer tous les joueurs de la partie
    std::vector<Joueur>& tous_joueurs = partie.getJoueurs();

    // Parcourir tous les joueurs y compris celui qui joue Espion
    for(Joueur& un_joueur : tous_joueurs){

        // Seuls les adversaires peuvent utiliser Douves
        if(&un_joueur != &joueur){

            bool protege = false;
            std::string reponse;

            if(un_joueur.peutSeDefendre()){

                std::cout << un_joueur.getNomJoueur()
                          << ", voulez-vous reveler Douves pour vous proteger ? (o/n) : ";

                std::cin >> reponse;

                while(reponse != "o" && reponse != "n"){

                    std::cout << "Reponse invalide. Tapez o ou n : ";
                    std::cin >> reponse;
                }

                if(reponse == "o"){

                    protege = true;
                    partie.ajouterHistorique(un_joueur.getNomJoueur() + " se protege avec Douves contre Espion.");

                    std::cout << un_joueur.getNomJoueur()
                              << " revele Douves et bloque l'attaque.\n";
                }
            }

            if(protege){
                continue;
            }
        }

        // Reveler la premiere carte du deck
        std::vector<Carte*> cartesRevelees = un_joueur.revelerCarte(1);

        // Cas ou le joueur ne possede aucune carte a reveler
        if(cartesRevelees.empty()){
            partie.ajouterHistorique(un_joueur.getNomJoueur() + " n'a aucune carte a reveler.");
            continue;
        }

        // Recuperer la carte revelee
        Carte* carte = cartesRevelees[0];
        partie.ajouterHistorique(un_joueur.getNomJoueur() + " revele " + carte->getNom() + ".");

        // Le joueur qui a joue Espion decide du sort de cette carte
        std::cout << joueur.getNomJoueur()
                  << ", voulez-vous defausser "
                  << carte->getNom()
                  << " de " << un_joueur.getNomJoueur()
                  << " ? (o/n) : ";

        std::string reponse;
        std::cin >> reponse;

        while(reponse != "o" && reponse != "n"){

            std::cout << "Reponse invalide. Tapez o ou n : ";
            std::cin >> reponse;
        }

        if(reponse == "o"){

            // Placer la carte dans la defausse de son proprietaire
            un_joueur.recevoir(carte);
            partie.ajouterHistorique(un_joueur.getNomJoueur() + " defausse " + carte->getNom() + ".");

            std::cout << carte->getNom()
                      << " rejoint la defausse de "
                      << un_joueur.getNomJoueur() << ".\n";
        }
        else{

            // Remettre la carte sur le dessus du deck
            // On reutilise la methode existante dans Joueur
            un_joueur.ajouterAuDeck(carte);
            partie.ajouterHistorique(un_joueur.getNomJoueur() + " conserve " + carte->getNom() + " sur son deck.");

            std::cout << carte->getNom()
                      << " est replacee sur le dessus du deck de "
                      << un_joueur.getNomJoueur() << ".\n";
        }
    }
}

// Description affichee sur la carte
std::vector<std::string> Espion::getDescription() const{

    return {
        "+1 Carte",
        "+1 Action",
        "Revelez 1 carte",
        "par joueur"
    };
}

Espion::~Espion(){
}
