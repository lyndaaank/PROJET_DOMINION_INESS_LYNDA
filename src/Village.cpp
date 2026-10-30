#include "Village.hpp"
#include "Joueur.hpp"

Village::Village()
    : CarteAction(false, false, "Village", 3)
{
}

std::vector<std::string> Village::getDescription() const {

    return {"+1 Carte", "+2 Actions"};
}



void Village::appliquerEffet(Joueur& joueur, Partie& /*partie*/){

    joueur.piocher(1);
    joueur.ajouterActions(2);
}
