
#include "Voleur.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"

#include <iostream>
#include <string>
#include <vector>

// Constructeur
Voleur::Voleur()
    : CarteAction(true, false, "Voleur", 4)
{
}

// attaquer les adversaires et voler un Tresor revele
void Voleur::appliquerEffet(Joueur& joueur, Partie& partie){

    // Recuperer les joueurs de la partie
std::vector<Joueur>& tous_joueurs = partie.getJoueurs();

    // Parcourir les joueurs pour trouver les adversaires
    for(Joueur& adversaire : tous_joueurs){

        // Ne pas attaquer le joueur qui joue Voleur
        if(&adversaire == &joueur){
            continue;
        }

        std::cout << joueur.getNomJoueur()
                  << " attaque " << adversaire.getNomJoueur()
                  << " avec Voleur !\n";

        bool protege = false;
        std::string reponse;

        // Verifier si l'adversaire possede une carte Reaction
        if(adversaire.peutSeDefendre()){

            std::cout << adversaire.getNomJoueur()
                      << ", voulez-vous reveler Douves pour vous proteger ? (o/n) : ";

            std::cin >> reponse;

            // Verifier la reponse
            while(reponse != "o" && reponse != "n"){

                std::cout << "Reponse invalide. Tapez o ou n : ";
                std::cin >> reponse;
            }

            if(reponse == "o"){

                protege = true;
                partie.ajouterHistorique(adversaire.getNomJoueur() + " se protege avec Douves contre Voleur.");

                std::cout << adversaire.getNomJoueur()
                          << " revele Douves et bloque l'attaque.\n";
            }
        }

        // Si l'adversaire est protege ne pas effectuer l'attaque
        if(protege){
            continue;
        }

        // Reveler jusqu'a 2 cartes du deck adverse
        std::vector<Carte*> cartesRevelees = adversaire.revelerCarte(2);
        for(Carte* revelee : cartesRevelees)
            partie.ajouterHistorique(adversaire.getNomJoueur() + " revele " + revelee->getNom() + ".");

        // Rechercher les Tresors parmi les cartes revelees
        std::vector<Carte*> tresors;

        for(Carte* carte : cartesRevelees){

            if(carte->getType() == TRESOR){
                tresors.push_back(carte);
            }
        }

        // Pointeur vers le Tresor qui sera retire au joueur adverse
        Carte* tresorChoisi = nullptr;

        // CAS 1 Aucun Tresor revele
        if(tresors.empty()){

            std::cout << "Aucun Tresor revele.\n";
            partie.ajouterHistorique(adversaire.getNomJoueur() + " ne revele aucun Tresor.");
        }

        // CAS 2  Un seul Tresor revele
        else if(tresors.size() == 1){

            tresorChoisi = tresors[0];

        
        }

        // CAS 3 Deux Tresors reveles
        else{

            std::cout << "\nDeux Tresors ont ete reveles.\n";

            // Afficher les Tresors pour le choix de l'attaquant
            for(int i = 0; i < (int)tresors.size(); i++){

                std::cout << i + 1 << ". "
                          << tresors[i]->getNom() << "\n";
            }

            std::cout << joueur.getNomJoueur()
                      << ", choisissez le Tresor a mettre au rebut : ";

            int numero = partie.verifSaisieNumero();

            // Verifier que le numero correspond a un Tresor
            while(numero < 1 || numero > (int)tresors.size()){

                std::cout << "Numero invalide. Choisissez 1 ou 2 : ";
                numero = partie.verifSaisieNumero();
            }

            // Recuperer le Tresor choisi
            tresorChoisi = tresors[numero - 1];
        }

        // Traiter le Tresor selectionne, s'il y en a un
        if(tresorChoisi != nullptr){

            std::cout << tresorChoisi->getNom()
                      << " est le Tresor choisi pour le rebut.\n";

            // Demander si l'attaquant souhaite recuperer ce Tresor
            std::cout << joueur.getNomJoueur()
                      << ", voulez-vous recuperer ce Tresor ? (o/n) : ";

            std::cin >> reponse;

            while(reponse != "o" && reponse != "n"){

                std::cout << "Reponse invalide. Tapez o ou n : ";
                std::cin >> reponse;
            }

            if(reponse == "o"){

                // L'attaquant gagne directement le Tresor dans sa defausse
                joueur.recevoir(tresorChoisi);
                partie.ajouterHistorique(joueur.getNomJoueur() + " vole " + tresorChoisi->getNom() + " a " + adversaire.getNomJoueur() + ".");

                std::cout << joueur.getNomJoueur()
                          << " recupere " << tresorChoisi->getNom()
                          << " dans sa defausse.\n";
            }
            else{

                // Le Tresor reste dans le rebut commun
                partie.mettreAurebut(tresorChoisi);

                std::cout << tresorChoisi->getNom()
                          << " est place dans le rebut commun.\n";
            }
        }

        // Defausser toutes les autres cartes revelees
        for(Carte* carte : cartesRevelees){

            if(carte != tresorChoisi){

                adversaire.recevoir(carte);
                partie.ajouterHistorique(adversaire.getNomJoueur() + " defausse " + carte->getNom() + ".");

                std::cout << carte->getNom()
                          << " rejoint la defausse de "
                          << adversaire.getNomJoueur() << ".\n";
            }
        }
    }
}

// Description affichee sur la carte
std::vector<std::string> Voleur::getDescription() const{

    return {
        "Revelez 2 cartes",
        "chez l'adversaire",
        "Rebutez 1 Tresor",
        "Vous pouvez le gagner"
    };
}

