#include "CarteAction.hpp"
#include <iostream>


CarteAction :: CarteAction(bool attaque , bool reaction, std :: string nom, int cout, std :: string type)
    : m_Attaque(attaque), m_Reaction(reaction)
{
    Carte(nom, cout, type);
    std :: cout << "Creation Carte Action"<< this << std :: endl;
}

bool CarteAction :: getAttaque()const{
    return m_Attaque;
}
bool CarteAction :: getReaction()const{
    return m_Reaction;
}

CarteAction :: ~CarteAction(){
    std :: cout << "Destructino Carte Action"<< this << std :: endl;
}

