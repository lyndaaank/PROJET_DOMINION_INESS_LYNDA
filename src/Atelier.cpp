#include "Atelier.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include "Reserve.hpp"
#include <iostream>

Atelier::Atelier()
    : CarteAction(false, false, "Atelier", 3)
{
}


void Atelier::appliquerEffet(Joueur& joueur, Partie& partie){

    Reserve& reserve = partie.getReserve();

    // Verifier qu'il existe au moins une carte eligible dans la reserve
    if(!reserve.existeCarteSelonCout(4)){
        std::cout << "Aucune carte disponible coutant 4 pieces ou moins.\n";
        partie.ajouterHistorique("Aucune carte disponible pour Atelier.");
        return;
    }

    bool choixValide = false;

    while(!choixValide){

       
        reserve.afficherCartesSelonCout(4);

      
        std::cout << "Choisissez une carte coutant 4 pieces maximum : ";
        int numero = partie.verifSaisieNumero();

        
        std::string nom = reserve.getNom(numero);

        if(nom == ""){
            std::cout << "Numero invalide.\n";
            continue;
        }

      
        if(!reserve.estDisponible(nom)){
            std::cout << "Cette carte n'est plus disponible.\n";
            continue;
        }

        if(reserve.getCout(nom) > 4){
            std::cout << "Cette carte coute plus de 4 pieces.\n";
            continue;
        }

        
        Carte* carte = reserve.retirerCarte(nom);

        if(carte != nullptr){

            
            joueur.recevoir(carte);
            partie.ajouterHistorique(joueur.getNomJoueur() + " gagne " + carte->getNom() + ".");

            std::cout << "Vous avez gagne la carte "
                      << carte->getNom()
                      << ". Elle a ete ajoutee a votre defausse.\n";

           
            choixValide = true;
        }
    }
}


std::vector<std::string> Atelier::getDescription() const{

    return {
        "Gagnez une carte",
        "coutant jusqu'a",
        "4 pieces"
    };
}
