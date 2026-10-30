#include "CarteMalediction.hpp"
#include <iostream>

CarteMalediction::CarteMalediction(int points, const std::string& nom, int cout)
    : Carte(nom, cout, MALEDICTION), m_Points(points)
{
}


CarteMalediction:: ~CarteMalediction()
{
}


int CarteMalediction::getPoints() const{

    return m_Points;//retorune -1 c juste dans le consteurs j'ai deja mis 

}

std::vector<std::string> CarteMalediction::getDescription() const {
    if (m_Points == 1 || m_Points == -1)
        return {std::to_string(m_Points) + " Point"};

    return {std::to_string(m_Points) + " Points"};
}
