#include "Partie.hpp"
#include "Joueur.hpp"

#include "Carte.hpp"
#include "CarteTresor.hpp"
#include "CarteVictoire.hpp"
#include "CarteMalediction.hpp"
#include"CarteAction.hpp"


#include <iostream>
#include<algorithm>



// Initialise le joueur avec son nom et ses compteurs de début de tour.
Joueur::Joueur(const std::string& nom)
    : m_nom(nom), m_actions(1), m_achats(1), m_pieces(0), m_nombreTours(0)
{

}


// Ajoute des actions au joueur, notamment grâce aux effets des cartes Action.
void Joueur::ajouterActions(int n)
{

    m_actions += n;
}


// Ajoute des achats au joueur, notamment grâce aux effets des cartes Action.
void Joueur::ajouterAchats(int n)
{

    m_achats += n;
}


// Ajoute des pièces au joueur, notamment grâce aux effets des cartes Action.
void Joueur::ajouterPieces(int n)
{


    m_pieces += n;
}


// Réinitialise les compteurs du joueur pour son prochain tour, appelée par ajuster().
void Joueur::reinitialiserTour()
{

    m_actions = 1;
    m_achats = 1;
    m_pieces = 0;
}


// Pioche n cartes du deck vers la main et appelle melanger() si le deck est vide.
//verifie egalement les différent cas possible 
void Joueur::piocher(int n){


    for(int i = 0; i < n; i++){

        if(m_deck.empty()){

            if(m_defausse.empty()){
                break;
            }

            m_deck = m_defausse;
            m_defausse.clear();
            melanger();

        }

        Carte* carte = m_deck.back();
        m_deck.pop_back();
        m_main.push_back(carte);

    }
}


// Ajoute une carte au deck du joueur, notamment lors de l'initialisation par Partie.
void Joueur::ajouterAuDeck(Carte* carte){

    m_deck.push_back(carte);
}


// Défausse la main et les cartes jouées, puis appelle piocher() et reinitialiserTour().
void Joueur::ajuster(Partie* partie){


    while(m_main.empty() == false){
        Carte* carte = m_main.back();
        m_main.pop_back();
        m_defausse.push_back(carte);
        if(partie != nullptr)
            partie->ajouterHistorique(m_nom + " defausse " + carte->getNom() + ".");
    }


    while(m_cartesJouees.empty() == false){
        Carte* carte = m_cartesJouees.back();
        m_cartesJouees.pop_back();
        m_defausse.push_back(carte);
        if(partie != nullptr)
            partie->ajouterHistorique(m_nom + " defausse " + carte->getNom() + ".");

    }

    piocher(5);
    reinitialiserTour();

}


// Joue une carte Action de la main et applique son effet en communiquant avec Partie.
void Joueur::jouerAction(Carte* carte, Partie& partie){



    if(m_actions <= 0){
        std::cout << "Vous n'avez plus d'actions disponibles ! " << std::endl;
        return;
    }

    if(carte == nullptr || carte->getType() != ACTION) {
        std::cout << "Cette carte n'est pas une Action ! " << std::endl;
        return;
    }

    for(int i = 0; i < (int)m_main.size(); i++){

        if(m_main[i] == carte) {
            m_main.erase(m_main.begin() + i);
            m_cartesJouees.push_back(carte);

            m_actions--;

            std::cout << "\n" << m_nom << " joue la carte "
                      << carte->getNom() << ".\n";
            partie.ajouterHistorique(m_nom + " joue " + carte->getNom() + ".");
            int mainAvant = getNombreCartesMain();
            int actionsAvant = m_actions;
            int achatsAvant = m_achats;
            int piecesAvant = m_pieces;
            carte->appliquerEffet(*this, partie);
            int pioche = getNombreCartesMain() - mainAvant;
            if(pioche > 0)
                partie.ajouterHistorique(m_nom + " pioche " + std::to_string(pioche) + " carte(s).");
            if(m_actions > actionsAvant)
                partie.ajouterHistorique(m_nom + " gagne " + std::to_string(m_actions - actionsAvant) + " action(s).");
            if(m_achats > achatsAvant)
                partie.ajouterHistorique(m_nom + " gagne " + std::to_string(m_achats - achatsAvant) + " achat(s).");
            if(m_pieces > piecesAvant)
                partie.ajouterHistorique(m_nom + " gagne " + std::to_string(m_pieces - piecesAvant) + " piece(s).");

            break;
        }

    }

}



 // Joue une carte Trésor de la main et ajoute sa valeur aux pièces du joueur.
void Joueur::jouerTresor(Carte* carte){



    if(carte == nullptr || carte->getType() != TRESOR){
        std::cout << "Cette carte n'est pas un Tresor !" << std::endl;
        return;
    }

    for(int i = 0; i < (int)m_main.size(); i++){

        if(m_main[i] == carte){

            CarteTresor* tresor = static_cast<CarteTresor*>(carte);

            ajouterPieces(tresor->getValeur());

            m_main.erase(m_main.begin() + i);
            m_cartesJouees.push_back(carte);

            break;
        }
    }
}



// Mélange les cartes du deck 
void Joueur :: melanger(){
    std::random_shuffle(m_deck.begin(), m_deck.end());
}


// Reçoit une carte, notamment depuis Reserve, et la place dans la défausse.
void Joueur :: recevoir (Carte* carte){
    m_defausse.push_back(carte);
}




// Retourne le nombre d'achats disponibles, utilisé notamment par Partie::phaseAchat().
int Joueur :: getAchats()const {
    return m_achats;
}


// Retourne le nombre d'actions disponibles, utilisé notamment par Partie::phaseAction().
int Joueur :: getActions()const{
    return m_actions;
}


// Retourne le nombre de pièces disponibles, utilisé notamment par Partie::phaseAchat().
int Joueur :: getPieces()const{
    return m_pieces;
}


// Retourne le pointeur vers une carte de la main selon son numéro, utilisé par Partie.
Carte* Joueur :: getCarteMain(int numero) const{
    if(numero >= 1 && numero <= (int)m_main.size()){
        return m_main[numero-1];
    }
    return nullptr;
}

std::string Joueur::getNomJoueur() const {

    return m_nom;

}

// Vérifie si la main contient au moins une carte du type demandé, notamment pour la phase Action.
bool Joueur :: aCarte(TypeCarte type) const
{
    for (Carte* carte : m_main){
        if (carte -> getType()== type){
            return true;
        }
    }
    return false;
}



int Joueur::getNombreTours() const{
    return m_nombreTours;
}

void Joueur :: ajouterTour(){
    m_nombreTours++; 
}


int Joueur :: getNombreTotalCartes() const{

     return m_deck.size() + m_main.size() + m_defausse.size() +  m_cartesJouees.size();

}


// Calcule le score total du joueur en parcourant toutes ses cartes
int Joueur::calculerScore() const{

    int score = 0;

    // Parcourir les cartes du deck
    for(Carte* carte : m_deck){

        CarteVictoire* victoire = dynamic_cast<CarteVictoire*>(carte);
        CarteMalediction* malediction = dynamic_cast<CarteMalediction*>(carte);

        if(victoire != nullptr){
        //*this c'est le joueur
            score += victoire->calculerPoints(*this);
        }
        else if(malediction != nullptr){
            score += malediction->getPoints();
        }
    }

    // Parcourir les cartes de la main
    for(Carte* carte : m_main){

        CarteVictoire* victoire = dynamic_cast<CarteVictoire*>(carte);
        CarteMalediction* malediction = dynamic_cast<CarteMalediction*>(carte);

        if(victoire != nullptr){
            score += victoire->calculerPoints(*this);
        }
        else if(malediction != nullptr){
            score += malediction->getPoints();
        }
    }

    // Parcourir les cartes de la defausse
    for(Carte* carte : m_defausse){

        CarteVictoire* victoire = dynamic_cast<CarteVictoire*>(carte);
        CarteMalediction* malediction = dynamic_cast<CarteMalediction*>(carte);

        if(victoire != nullptr){
            score += victoire->calculerPoints(*this);
        }
        else if(malediction != nullptr){
            score += malediction->getPoints();
        }
    }

    // Parcourir les cartes jouees
    for(Carte* carte : m_cartesJouees){

        CarteVictoire* victoire = dynamic_cast<CarteVictoire*>(carte);
        CarteMalediction* malediction = dynamic_cast<CarteMalediction*>(carte);

        if(victoire != nullptr){
            score += victoire->calculerPoints(*this);
        }
        else if(malediction != nullptr){
            score += malediction->getPoints();
        }
    }

    return score;
}

//festin 
bool Joueur::retirerCarteJouee(Carte* carte){

    for(int i = 0; i < (int)m_cartesJouees.size(); i++){

        if(m_cartesJouees[i] == carte){

            m_cartesJouees.erase(m_cartesJouees.begin() + i);
            return true;
        }
    }
    return false;
}


//chapelle
bool Joueur::retirerCarteMain(Carte* carte){

    for(int i = 0; i < (int)m_main.size(); i++){

        if(m_main[i] == carte){

            m_main.erase(m_main.begin() + i);
            return true;
        }
    }
    return false;
}




// Verifie si le joueur possede une carte Reaction dans sa main
bool Joueur::peutSeDefendre() const{

    for(Carte* carte : m_main){

        if(carte != nullptr && carte->getType() == ACTION){

            CarteAction* action = dynamic_cast<CarteAction*>(carte);

            if(action != nullptr && action->getReaction()){
                return true;
            }
        }
    }

    return false;
}


// Reveler n cartes du dessus du deck avec gestion des cas particuliers
std::vector<Carte*> Joueur::revelerCarte(int n){

    std::vector<Carte*> cartesRevelees;

    for(int i = 0; i < n; i++){

        if(m_deck.empty()){

            if(m_defausse.empty()){
                break;
            }

            m_deck = m_defausse;
            m_defausse.clear();
            melanger();

            std::cout << m_nom<< " melange sa defausse pour reformer son deck.\n";
                      
        }

        Carte* carte = m_deck.back();
        m_deck.pop_back();

        cartesRevelees.push_back(carte);

        std::cout << m_nom << " revele : "<< carte->getNom() << ".\n";
                  
    }

    if(cartesRevelees.empty()){
        std::cout << m_nom << " n'a aucune carte a reveler.\n";
    }

    return cartesRevelees;
}


// Affiche les statistiques du joueur en fin de partie
void Joueur::afficherStatistiques() const{

    std::cout << "\nJoueur : " << m_nom << "\n";
    std::cout << "Tours joues : " << m_nombreTours << "\n";
    std::cout << "Nombre total de cartes : " << getNombreTotalCartes() << "\n";
    std::cout << "Score final : " << calculerScore() << "\n";
}


// Affiche les cartes de la main du joueur.
void Joueur::afficher_main() const
{
    std::cout << "\n----------Ma Main----------\n";

    for(int debut = 0; debut < static_cast<int>(m_main.size()); debut += 3)
    {
        std::vector<std::string> carte1;
        std::vector<std::string> carte2;
        std::vector<std::string> carte3;


        if(debut < static_cast<int>(m_main.size())){
            carte1 = m_main[debut]->getAffichage(debut + 1);
        }
        if(debut + 1 < static_cast<int>(m_main.size())){
            carte2 = m_main[debut + 1]->getAffichage(debut + 2);
        }
        if(debut + 2 < static_cast<int>(m_main.size())){
            carte3 = m_main[debut + 2]->getAffichage(debut + 3);
        }
        for(int ligne = 0; ligne < 13; ligne++)
        {
            if(!carte1.empty()) std::cout << carte1[ligne] << " ";
            if(!carte2.empty()) std::cout << carte2[ligne] << " ";
            if(!carte3.empty()) std::cout << carte3[ligne] << " ";

            std::cout << "\n";
        }

        std::cout << "\n";
    }
}









int Joueur::getNombreCartesMain() const { return static_cast<int>(m_main.size()); }

void Joueur::defausser(Carte* carte){
    for(auto it = m_main.begin(); it != m_main.end(); ++it){
        if(*it == carte){
            m_defausse.push_back(carte);
            m_main.erase(it);
            return;
        }
    }
}
