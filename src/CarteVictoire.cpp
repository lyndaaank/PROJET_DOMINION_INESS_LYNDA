#include "CarteVictoire.hpp"
#include <iostream>




CarteVictoire::CarteVictoire(int points, const std::string& nom, int cout)
    : Carte(nom, cout, VICTOIRE), m_Points(points)
{
}

int CarteVictoire :: getPoints()const{
    return m_Points;
}


//methode virtuelle redefini dans jardins
int CarteVictoire :: calculerPoints(const Joueur& /*joueur*/)const{
    return m_Points;
}

CarteVictoire :: ~CarteVictoire()
{
}

std::vector<std::string> CarteVictoire::getDescription() const {
    if (m_Points == 1 || m_Points == -1)
        return {std::to_string(m_Points) + " Point"};

    return {std::to_string(m_Points) + " Points"};
}
