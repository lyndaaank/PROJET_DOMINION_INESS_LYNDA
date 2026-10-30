#include "Sorciere.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include <iostream>
#include <string>

Sorciere::Sorciere()
    : CarteAction(true, false, "Sorciere", 5)
{
}

void Sorciere::appliquerEffet(Joueur& joueur, Partie& partie)
{
    std::string reponse;

    joueur.piocher(2);
   

    std::vector<Joueur>& tous_joueurs = partie.getJoueurs();

    for(Joueur& un_joueur : tous_joueurs){

        // On compare les adresses memoires pour ne pas attaquer le joueur courant
        if(&un_joueur != &joueur){

            bool protege = false;

            if(un_joueur.peutSeDefendre()){

                std::cout << un_joueur.getNomJoueur()
                          << " ,voulez-vous vous defendre de cette attaque ? (o/n)\n";

                std::cin >> reponse;

                while(reponse != "o" && reponse != "n"){

                    std::cout << "Reponse invalide. Tapez o ou n : ";
                    std::cin >> reponse;
                }

                if(reponse == "o"){

                    protege = true;
                    partie.ajouterHistorique(un_joueur.getNomJoueur() + " se protege avec Douves contre Sorciere.");

                    std::cout << un_joueur.getNomJoueur()
                              << " revele Douves pour se proteger de l'attaque"
                              << std::endl;
                }
            }

            if(!protege){

                Carte* carte = partie.getReserve().retirerCarte("Malediction");

                if(carte != nullptr){

                    un_joueur.recevoir(carte);
                    partie.ajouterHistorique(un_joueur.getNomJoueur() + " recoit une Malediction.");

                    std::cout << un_joueur.getNomJoueur()
                              << " recoit une carte Malediction.\n";
                } else {
                    partie.ajouterHistorique("Aucune Malediction disponible pour " + un_joueur.getNomJoueur() + ".");
                }
            }
        }
    }
}

Sorciere::~Sorciere()
{
}

std::vector<std::string> Sorciere::getDescription() const
{
    return {
        "+2 Cartes",
        "Chaque adversaire",
        "recoit une carte",
        "Malediction"
    };
}
