#include "Sorciere.hpp"

Sorciere::Sorciere()
    : CarteAction(true, false, "Sorciere", 5)
{
}

void Sorciere::appliquerEffet(Joueur& /*joueur*/, Partie& /*partie*/)
{
    // Effet à implémenter plus tard
}

Sorciere::~Sorciere()
{
}
