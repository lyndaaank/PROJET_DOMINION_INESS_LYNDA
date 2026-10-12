#include "CarteTresor.hpp"
#include <iostream>


CarteTresor::CarteTresor(int tresors, const std::string& nom, int cout)
    : Carte(nom, cout, TRESOR), m_Valeur(tresors)
{
}

CarteTresor :: ~CarteTresor()
{
}

