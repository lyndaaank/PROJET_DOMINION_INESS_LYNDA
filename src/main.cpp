#include <iostream>
#include<ctime>
#include<cstdlib>
#include<exception>

#include "Carte.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include "Village.hpp"



int main()
{

    try{
    //initialisation de nombres pseudo aléatoires
        srand(time(nullptr));
    
    
    
        Partie partie;
        partie.initialiser();
        partie.jouer();
    }
        catch(const std::exception& r) {
            std::cerr << "Erreur : "<<e.what() <<std::endl;
            return 1;

        }


    return 0;
}



