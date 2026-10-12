#include "CarteVictoire.hpp"
#include <iostream>




CarteVictoire::CarteVictoire(int points, const std::string& nom, int cout)
    : Carte(nom, cout, VICTOIRE), m_Points(points)
{
}

int CarteVictoire :: getPoints()const{
    return m_Points;
}

int CarteVictoire :: calculerPoints(const Joueur& /*joueur*/)const{
    return m_Points;
}


CarteVictoire :: ~CarteVictoire()
{
}

