#include "CarteMalediction.hpp"
#include <iostream>

CarteMalediction::CarteMalediction(int points, const std::string& nom, int cout)
    : Carte(nom, cout, MALEDICTION), m_Points(points)
{
}


CarteMalediction:: ~CarteMalediction()
{
}

