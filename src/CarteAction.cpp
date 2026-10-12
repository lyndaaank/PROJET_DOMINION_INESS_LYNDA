#include "CarteAction.hpp"
#include <iostream>


CarteAction::CarteAction(bool attaque, bool reaction, const std::string& nom, int cout)
    : Carte(nom, cout, ACTION),  m_Attaque(attaque), m_Reaction(reaction)
{
}

bool CarteAction :: getAttaque()const{
    return m_Attaque;
}
bool CarteAction :: getReaction()const{
    return m_Reaction;
}

CarteAction :: ~CarteAction()
{
}

