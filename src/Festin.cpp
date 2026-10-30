#include "Festin.hpp"
#include <iostream>
#include "Reserve.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"

Festin::Festin()
    : CarteAction(false, false, "Festin", 4)
{
}

void Festin::appliquerEffet(Joueur& joueur, Partie& partie)
{
    int numero;

    Reserve& reserve = partie.getReserve();

    // Mettre Festin au rebut
       
    if(joueur.retirerCarteJouee(this)){
        partie.mettreAurebut(this);

        std::cout << "Festin a ete mis au rebut.\n";
    }

    // Verifier s'il existe une carte disponible coutant 5 pieces maximum sinon bloqué dans jeu
    if(!reserve.existeCarteSelonCout(5)){
        std::cout << "Aucune carte disponible coutant 5 pieces ou moins.\n";
        partie.ajouterHistorique("Aucune carte disponible pour Festin.");
        return;
    }

    bool choixValide = false;

    while(!choixValide){

        reserve.afficherCartesSelonCout(5);

        std::cout << "Vous gagnez une carte coutant jusqu'a 5 pieces, choisissez une carte : \n";

        numero = partie.verifSaisieNumero();

        std::string carte_select = reserve.getNom(numero);

        if(carte_select != ""){

            if(reserve.estDisponible(carte_select)){

                int prix_carte_select = reserve.getCout(carte_select);

                if(prix_carte_select <= 5){

                    Carte* carte = reserve.retirerCarte(carte_select);

                    if(carte != nullptr){

                        joueur.recevoir(carte);
                        partie.ajouterHistorique(joueur.getNomJoueur() + " gagne " + carte->getNom() + ".");

                        choixValide = true;

                        std::cout << "Vous avez gagne la carte "
                                  << carte->getNom()
                                  << ". Elle a ete ajoutee a votre defausse.\n";
                    }
                }
                else {
                    std::cout << "Vous avez selectionne une carte non selectionnable" << std::endl;
                }
            }
            else {
                std::cout << "Cette carte n'est plus disponible" << std::endl;
            }
        }
        else {
            std::cout << "Il faut choisir une carte presente dans la reserve" << std::endl;
        }
    }
}

Festin::~Festin()
{
}

std::vector<std::string> Festin::getDescription() const
{
    return {
        "Mettez cette carte",
        "au rebut, puis",
        "gagnez une carte",
        "de cout max 5"
    };
}
