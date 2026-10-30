#include "Milice.hpp"

#include "Reserve.hpp"
#include "Carte.hpp"

#include "CarteTresor.hpp"
#include "CarteVictoire.hpp"
#include "CarteMalediction.hpp"

#include "Atelier.hpp"
#include "Bucheron.hpp"
#include "Chapelle.hpp"
#include "Douves.hpp"
#include "Festin.hpp"
#include "Jardins.hpp"
#include "Laboratoire.hpp"
#include "Sorciere.hpp"
#include "Village.hpp"
#include "Voleur.hpp"
#include "Espion.hpp"

#include <iostream>


// Crée une carte selon son nom
Carte* Reserve::creerCarte(const std::string& nom){

    if(nom == "Cuivre"){
        return new CarteTresor(1, "Cuivre", 0);
    }

    if(nom == "Argent"){
        return new CarteTresor(2, "Argent", 3);
    }

    if(nom == "Or"){
        return new CarteTresor(3, "Or", 6);
    }

    if(nom == "Domaine"){
        return new CarteVictoire(1, "Domaine", 2);
    }

    if(nom == "Duche"){
        return new CarteVictoire(3, "Duche", 5);
    }

    if(nom == "Province"){
        return new CarteVictoire(6, "Province", 8);
    }

    if(nom == "Malediction"){
        return new CarteMalediction(-1, "Malediction", 0);
    }

    if(nom == "Atelier"){
        return new Atelier();
    }

    if(nom == "Bucheron"){
        return new Bucheron();
    }

    if(nom == "Chapelle"){
        return new Chapelle();
    }

    if(nom == "Douves"){
        return new Douves();
    }

    if(nom == "Festin"){
        return new Festin();
    }

    if(nom == "Jardins"){
        return new Jardins();
    }

    if(nom == "Laboratoire"){
        return new Laboratoire();
    }

    if(nom == "Sorciere"){
        return new Sorciere();
    }

    if(nom == "Village"){
        return new Village();
    }

    if(nom == "Voleur"){
        return new Voleur();
    }

    if(nom == "Espion"){
        return new Espion();
    }
    if(nom == "Milice") return new Milice();

    return nullptr;
}


// Affiche une carte Royaume pour consulter sa description
void Reserve::afficherCarteRoyaume(const std::string& nom){

    Carte* carte = creerCarte(nom);

    if(carte == nullptr){
        std::cout << "Carte inconnue.\n";
        return;
    }

    // Reutiliser l'affichage des cartes deja programme
    std::vector<std::string> affichage = carte->getAffichage(0);

    std::cout << "\n";

    for(const std::string& ligne : affichage){
        std::cout << ligne << "\n";
    }

    // Supprimer la carte temporaire apres la consultation
    delete carte;
}


// Initialise les piles de cartes selon le mode de jeu et les cartes Royaume choisies
void Reserve::initialiser(bool modeRapide, const std::vector<std::string>& cartesChoisies){

    int quantite;

    // On suppose que les cartes initiales des deux joueurs sont deja comptabilisées séparement

    if(modeRapide){
        quantite = 1;
    }
    else{
        quantite = 46;
    }

    for(int i = 0; i < quantite; i++){
        m_pilesCartes["Cuivre"].push_back(creerCarte("Cuivre"));
    }

    if(modeRapide){
        quantite = 1;
    }
    else{
        quantite = 40;
    }

    for(int i = 0; i < quantite; i++){
        m_pilesCartes["Argent"].push_back(creerCarte("Argent"));
    }

    if(modeRapide){
        quantite = 1;
    }
    else{
        quantite = 30;
    }

    for(int i = 0; i < quantite; i++){
        m_pilesCartes["Or"].push_back(creerCarte("Or"));
    }

    if(modeRapide){
        quantite = 1;
    }
    else{
        quantite = 8;
    }

    for(int i = 0; i < quantite; i++){
        m_pilesCartes["Domaine"].push_back(creerCarte("Domaine"));
        m_pilesCartes["Duche"].push_back(creerCarte("Duche"));
        m_pilesCartes["Province"].push_back(creerCarte("Province"));
    }

    // Initialiser les Maledictions
    if(modeRapide){
        quantite = 1;
    }
    else{
        quantite = 10;
    }

    for(int i = 0; i < quantite; i++){
        m_pilesCartes["Malediction"].push_back(creerCarte("Malediction"));
    }

    // Initialiser uniquement les dix cartes Royaume selectionnees
    for(const std::string& nom : cartesChoisies){

        if(modeRapide){
            quantite = 1;
        }
        else if(nom == "Jardins"){
            quantite = 12;
        }
        else{
            quantite = 10;
        }

        for(int i = 0; i < quantite; i++){
            m_pilesCartes[nom].push_back(creerCarte(nom));
        }
    }
}


// Vérifie si une pile existe et contient encore des cartes
bool Reserve::estDisponible(const std::string& nom) const{

    auto carteTrouvee = m_pilesCartes.find(nom);

    if(carteTrouvee == m_pilesCartes.end()){
        return false;
    }

    if(carteTrouvee->second.empty()){
        return false;
    }

    return true;
}


// Retire une carte de la réserve et retourne son pointeur
Carte* Reserve::retirerCarte(const std::string& nom){

    if(estDisponible(nom)){

        Carte* carte = m_pilesCartes[nom].back();

        m_pilesCartes[nom].pop_back();

        return carte;
    }

    std::cout << "Il n'y a plus de carte " << nom << std::endl;

    return nullptr;
}


// Retourne le nom de la pile correspondant au numéro choisi
std::string Reserve::getNom(int numero) const{

    int i = 1;

    for(const auto& pile : m_pilesCartes){

        if(i == numero){
            return pile.first;
        }

        i++;
    }

    return "";
}


// Retourne le coût d'une carte à partir de son nom.
int Reserve::getCout(const std::string& nom) const{

    if(nom == "Cuivre") return 0;
    if(nom == "Argent") return 3;
    if(nom == "Or") return 6;

    if(nom == "Domaine") return 2;
    if(nom == "Duche") return 5;
    if(nom == "Province") return 8;
    if(nom == "Malediction") return 0;

    if(nom == "Atelier") return 3;
    if(nom == "Bucheron") return 3;
    if(nom == "Chapelle") return 2;
    if(nom == "Douves") return 2;
    if(nom == "Festin") return 4;
    if(nom == "Jardins") return 4;
    if(nom == "Laboratoire") return 5;
    if(nom == "Sorciere") return 5;
    if(nom == "Village") return 3;
    if(nom == "Voleur") return 4;
    if(nom == "Espion") return 4;
    if(nom == "Milice") return 4;

    return -1;
}


// Retourne les pointeurs de toutes les cartes présentes dans la réserve
std::vector<Carte*> Reserve::getToutesLesCartes() const{

    std::vector<Carte*> cartes;

    for(const auto& pile : m_pilesCartes){

        for(Carte* carte : pile.second){
            cartes.push_back(carte);
        }
    }

    return cartes;
}


// Vérifie si la pile Province est vide ou si trois piles sont vides
bool Reserve::conditionFinAtteinte() const{

    auto province = m_pilesCartes.find("Province");

    if(province != m_pilesCartes.end()){

        if(province->second.empty()){
            return true;
        }
    }

    int pilesVides = 0;

    for(const auto& pile : m_pilesCartes){

        if(pile.second.empty()){
            pilesVides++;
        }
    }

    if(pilesVides >= 3){
        return true;
    }

    return false;
}


void Reserve::afficherCartesSelonCout(int prixMax) const{

    int i = 1;

    std::cout << "\n----------Reserve----------\n";

    for(const auto& pile : m_pilesCartes){

        if(!pile.second.empty() && getCout(pile.first) <= prixMax){

            std::string couleur = "\033[34m";
            TypeCarte type = pile.second.back()->getType();
            if(type == TRESOR) couleur = "\033[33m";
            else if(type == VICTOIRE) couleur = "\033[32m";
            else if(type == MALEDICTION) couleur = "\033[31m";

            std::cout << couleur << i << ") " << pile.first
            << "\033[0m" << " | "
            << couleur << "Prix : " << getCout(pile.first)
            << "\033[0m" << " | "
            << couleur << "Stock : " << pile.second.size()
            << "\033[0m" << std::endl;
        }

        i++;
    }
}


//pour verifier quil existe bien une carte de ce cout la
bool Reserve::existeCarteSelonCout(int prixMax) const{

    for(const auto& pile : m_pilesCartes){

        if(!pile.second.empty() && getCout(pile.first) <= prixMax){
            return true;
        }
    }

    return false;
}


void Reserve::afficher_reserve() const
{
    int i = 1;

    std::cout << "\n----------Reserve----------\n";

    for(const auto& pile : m_pilesCartes)
    {
        std::string couleur = "";
        if(!pile.second.empty()){
            TypeCarte type = pile.second.back()->getType();
            if(type == TRESOR) couleur = "\033[93m";
            else if(type == VICTOIRE) couleur = "\033[92m";
            else if(type == MALEDICTION) couleur = "\033[91m";
            else couleur = "\033[96m";
        }
        std::cout << couleur << i << ") " << pile.first
          << "\033[0m" << " | "
          << couleur << "Prix : " << getCout(pile.first)
          << "\033[0m" << " | "
          << couleur << "Stock : " << pile.second.size()
          << "\033[0m" << std::endl;
        i++;
    }
}
