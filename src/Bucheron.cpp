#include "Bucheron.hpp"
#include"Joueur.hpp"

Bucheron::Bucheron()
    : CarteAction(false, false, "Bucheron", 3)
{
}


std::vector<std::string> Bucheron::getDescription() const {

    return {"+1 Achat", "+2 Pieces"};
}

void Bucheron::appliquerEffet(Joueur& joueur, Partie& /*partie*/){

    joueur.ajouterAchats(1);
    joueur.ajouterPieces(2);
}
