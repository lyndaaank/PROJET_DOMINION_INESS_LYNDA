#include <iostream>
#include<ctime>
#include<cstdlib>

#include "Carte.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include "Village.hpp"



int main()
{

//initialisation de nombres pseudo aléatoires
    srand(time(nullptr));



    Partie partie;
    partie.initialiser();
    partie.jouer();


    return 0;
}



