#include "Milice.hpp"
#include <iostream>



Milice::Milice()
    : CarteAction(true, false, "Milice", 4)
{
}


void Milice::appliquerEffet(Joueur& joueur, Partie& partie)
{
    std :: string reponse;
    joueur.ajouterPieces(2);
    std::cout << "Vous recevez +2 pièces.\n";

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
                    partie.ajouterHistorique(un_joueur.getNomJoueur() + " se protege avec Douves contre Milice.");

                    std::cout << un_joueur.getNomJoueur()
                              << " revele Douves pour se proteger de l'attaque"
                              << std::endl;
                }
            }

            if(!protege){
                partie.ajouterHistorique(un_joueur.getNomJoueur() + " est attaque par Milice.");
                int numero;

                while(un_joueur.getNombreCartesMain() > 3){
                    
                    std::cout << "====== Main de  :"<< un_joueur.getNomJoueur() << "====="<< std :: endl;
                    un_joueur.afficher_main();

                    std::cout << un_joueur.getNomJoueur() << " , Choisissez une carte a mettre dans la defausse : \n";
                    numero = partie.verifSaisieNumero();

                    Carte* carte = un_joueur.getCarteMain(numero);

                    while(carte == nullptr){

                        std::cout <<"Invalide. Tapez le numéro d'une carte presente dans votre main' : ";
                        numero = partie.verifSaisieNumero();
                        carte = un_joueur.getCarteMain(numero);
                    }

                    un_joueur.defausser(carte);
                    std::cout << un_joueur.getNomJoueur() << " , defausse la carte :" << carte->getNom()<< std :: endl;
                    partie.ajouterHistorique(un_joueur.getNomJoueur() + " defausse " + carte->getNom() + ".");
                    
                }

            }
    }
}}


std::vector<std::string> Milice:: getDescription() const {

    return {"+2 pieces", "Chaque adversaire", "defausse des cartes", "pour n'en garder", "que 3 en main."};


}

Milice::~Milice() {}
