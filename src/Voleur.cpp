#include "Voleur.hpp"

Voleur::Voleur()
    : CarteAction(true, false, "Voleur", 4)
{
}

void Voleur::appliquerEffet(Joueur& /*joueur*/, Partie&/* partie*/)
{
    // Effet à implémenter plus tard
}

Voleur::~Voleur()
{
}
