#include "Douves.hpp"
#include "Joueur.hpp"

Douves::Douves()
    : CarteAction(false, true, "Douves", 2)
{
}

void Douves::appliquerEffet(Joueur& joueur, Partie& partie)
{
    (void)partie;
    joueur.piocher(2);
}

Douves::~Douves()
{
}

std::vector<std::string> Douves::getDescription() const {
    return {"+2 Cartes", "Reaction : revelez", "pour bloquer une", "attaque"};
}
