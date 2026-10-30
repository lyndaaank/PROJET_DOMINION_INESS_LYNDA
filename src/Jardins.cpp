#include "Jardins.hpp"
#include "Joueur.hpp"

Jardins::Jardins()
    : CarteVictoire(0, "Jardins", 4)
{
}



int Jardins::calculerPoints(const Joueur& joueur) const
{
    return joueur.getNombreTotalCartes() / 10;
}

Jardins::~Jardins()
{
}

std::vector<std::string> Jardins::getDescription() const {
    return {
        "+1 Point pour",
        "chaque tranche de",
        "10 cartes possedees"
    };
}
