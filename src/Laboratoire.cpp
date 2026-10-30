#include "Laboratoire.hpp"
#include "Joueur.hpp"

Laboratoire::Laboratoire()
    : CarteAction(false, false, "Laboratoire", 5)
{
}

std::vector<std::string> Laboratoire::getDescription() const {
    return {"+2 Cartes", "+1 Action"};
}

void Laboratoire::appliquerEffet(Joueur& joueur, Partie& partie)
{
    (void)partie;
    joueur.piocher(2);
    joueur.ajouterActions(1);
}
