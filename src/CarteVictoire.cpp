#include "CarteVictoire.hpp"
#include <iostream>


CarteVictoire:: CarteVictoire(int points, std :: string nom, int cout, std :: string type)
    : Carte(nom, cout, type), m_Points(points)
{
    std :: cout << "Creation Carte Victoire"<< this << std :: endl;
}

int CarteVictoire :: getPoints()const{
    return m_Points;
}

int CarteVictoire :: calculerPoints(const Joueur& joueur)const{
    return m_Points;
}


CarteVictoire :: ~CarteVictoire(){
    std :: cout << "Destructino Carte Victoire"<< this << std :: endl;
}

