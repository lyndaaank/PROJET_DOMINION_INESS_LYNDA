#include "Carte.hpp"
#include <iostream>

Carte :: Carte (std ::string nom, int cout , std :: string type)
    : m_Nom(nom), m_Cout(cout), m_Type(type)
{
    std :: cout << "Construction Carte " << std :: endl;

}



Carte :: ~Carte(){
    std :: cout << "Destruction Carte " << std :: endl;
}
