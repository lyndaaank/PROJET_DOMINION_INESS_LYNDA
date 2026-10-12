#include "CarteAction.hpp"
#include <iostream>


CarteAction :: CarteAction(bool attaque , bool reaction, std :: string nom, int cout, std :: string type)
    : Carte(nom, cout, type), m_Attaque(attaque), m_Reaction(reaction)
{
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

