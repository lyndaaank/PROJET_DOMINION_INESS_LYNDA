#include "Chapelle.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include <iostream>

Chapelle::Chapelle()
    : CarteAction(false, false, "Chapelle", 2)
{
}

// Retourne la description de la carte pour l'affichage
std::vector<std::string> Chapelle::getDescription() const{

    return {"Mettez au rebut", "jusqu'a 4 cartes", "de votre main"};
}

// Permet au joueur de mettre au rebut jusqu'a 4 cartes de sa main
void Chapelle::appliquerEffet(Joueur& joueur, Partie& partie){

    int numero;

    for(int i = 0; i < 4; i++){

        if(joueur.getCarteMain(1) == nullptr){//juste pour verifier si on a carte en main 
            std::cout << "Vous n'avez pas de cartes en main.\n";
            break;
        }

        joueur.afficher_main();

        std::cout << "Choisissez une carte a mettre au rebut (0 pour terminer) : ";
        numero = partie.verifSaisieNumero();

        if(numero == 0){
            break;
        }

        Carte* carte = joueur.getCarteMain(numero);

        if(carte == nullptr){
            std::cout << "Numero de carte invalide." << std::endl;
            i--;
            continue;
        }

        if(joueur.retirerCarteMain(carte)){

            partie.mettreAurebut(carte);

            std::cout << "La carte " << carte->getNom()
                      << " a ete mise au rebut." << std::endl;
        }
    }
}
