#include "Carte.hpp"
#include <iostream>


Carte::Carte(const std::string& nom, int cout, TypeCarte type)
    : m_nom(nom), m_cout(cout), m_type(type)
{
}


Carte::~Carte()
{
}


void Carte::afficher() const
{
    std::cout << "Nom : " << m_nom << std::endl;
    std::cout << "Cout : " << m_cout << std::endl;
    std::cout << "Type : ";

    switch (m_type)
    {
        case TRESOR:
            std::cout << "Tresor";
            break;

        case VICTOIRE:
            std::cout << "Victoire";
            break;

        case MALEDICTION:
            std::cout << "Malediction";
            break;

        case ACTION:
            std::cout << "Action";
            break;
    }

    std::cout << std::endl;
}


std::string Carte::getNom() const
{
    return m_nom;
}


int Carte::getCout() const
{
    return m_cout;
}


TypeCarte Carte::getType() const
{
    return m_type;
}





