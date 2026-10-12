#include "Carte.hpp"
#include <iostream>

Carte :: Carte (std ::string nom, int cout , std :: string type)
    : m_Nom(nom), m_Cout(cout), m_Type(type)
{
    std :: cout << "Construction Carte " << this << std :: endl;

}

std::string Carte::getNom() const {
    return m_Nom;
}

int Carte::getCout() const {
    return m_Cout;
}

std::string Carte::getType() const {
    return m_Type;
}

Carte :: ~Carte(){
    std :: cout << "Destruction Carte " << this << std :: endl;
}
