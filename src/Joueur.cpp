#include "Joueur.hpp"
/*
#include "Carte.hpp"
#include "CarteAction.hpp"
#include "CarteTresor.hpp"
#include "CarteVictoire.hpp"
#include "CarteMalediction.hpp"
*/

#include <iostream>

Joueur::Joueur(const std::string& nom)
    : m_nom(nom), m_actions(1), m_achats(1), m_pieces(0)
{
}

/*
void Joueur::ajouterActions(int n)
{
    m_actions += n;
}

void Joueur::ajouterAchats(int n)
{
    m_achats += n;
}

void Joueur::ajouterPieces(int n)
{
    m_pieces += n;
}

void Joueur::reinitialiserTour()
{
    m_actions = 1;
    m_achats = 1;
    m_pieces = 0;
}*/
