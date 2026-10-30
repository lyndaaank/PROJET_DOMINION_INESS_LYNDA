#include "CarteTresor.hpp"
#include <iostream>


CarteTresor::CarteTresor(int tresors, const std::string& nom, int cout)
    : Carte(nom, cout, TRESOR), m_Valeur(tresors)
{
}

CarteTresor :: ~CarteTresor()
{
}

int CarteTresor::getValeur() const{
return m_Valeur;
}


std::vector<std::string> CarteTresor::getDescription() const{
    if(m_Valeur==1) return {"+1 Piece"};
    return {"+" + std::to_string(m_Valeur)+ "Pieces"};

}


