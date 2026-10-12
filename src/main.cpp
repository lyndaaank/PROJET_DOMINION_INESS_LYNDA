#include <iostream>

#include "Carte.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include "Village.hpp"

int main()
{
    std::cout << "TEST DOMINION" << std::endl;

    
    Carte carte("Cuivre", 0, TRESOR);
    carte.afficher();

    
    Joueur joueur("Joueur 1");
    std::cout << "Joueur cree avec succes !" << std::endl;

    
    Partie partie;
    std::cout << "Partie creee avec succes !" << std::endl;

    
    Village village;
    village.afficher();

    return 0;
}
