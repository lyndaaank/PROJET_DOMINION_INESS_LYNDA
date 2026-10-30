#include "Partie.hpp"
#include "CarteTresor.hpp"
#include "CarteVictoire.hpp"
#include "Carte.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>

// Initialise les attributs de la partie.
Partie::Partie()
    : m_joueurCourant(0), m_modeRapide(false)
{
}


// Destructeur de Partie, libère toutes les cartes créées.
Partie::~Partie()
{
    for(Carte* carte : m_toutesLesCartes){
        delete carte;
    }
}


// Affiche le message de bienvenue au lancement du jeu.
void Partie::afficherBienvenue() const{

    std::cout << "\n========================================\n";
    std::cout << "                DOMINION                \n";
    std::cout << "========================================\n";

    std::cout << "Bienvenue dans Dominion !\n";
    std::cout << "Jeu de cartes pour deux joueurs.\n";
    std::cout << "Le joueur qui possede le plus de points de victoire gagne.\n";

    std::cout << "========================================\n\n";
}


// Affiche le début du tour du joueur courant.
void Partie::afficherDebutTour() const{

    std::cout << "\n========================================\n";
    std::cout << "              NOUVEAU TOUR             \n";
    std::cout << "========================================\n";

    std::cout << "Joueur : " << m_joueurs[m_joueurCourant].getNomJoueur() << std::endl;

    std::cout << "========================================\n";
}


// Affiche le titre de la phase en cours.
void Partie::afficherPhase(const std::string& nom) const{

    std::cout << "\n----------------------------------------\n";
    std::cout << "              PHASE " << nom << std::endl;
    std::cout << "----------------------------------------\n";
}


// Lit un numéro au clavier et redemande une saisie si elle est invalide.
int Partie::verifSaisieNumero(){

    int numero;
    std::string ligne;

    while(true){

        if(!std::getline(std::cin >> std::ws, ligne)){ //std::ws c lespace apres ce qu'on a saisi seul difference avec ta methode
            std::cout << "Erreur de lecture." << std::endl;
            return -1;
        }

        std::stringstream lecture(ligne);

        if(lecture >> numero){

            lecture >> std::ws;

            if(lecture.eof() && numero >= 0){ //eof fin de chaine
                return numero;
            }
        }

        std::cout << "Numero invalide, recommencez : ";
    }
}


// Affiche les compteurs du joueur courant.
void Partie::afficherCompteurs() const{

    const Joueur& joueur = m_joueurs[m_joueurCourant];

    std::cout << "\nActions disponibles : " << joueur.getActions() << std::endl;
    std::cout << "Achats disponibles  : " << joueur.getAchats() << std::endl;
    std::cout << "Pieces disponibles  : " << joueur.getPieces() << std::endl;
}


// Initialise les joueurs, leurs decks et la réserve selon le mode choisi.
void Partie::initialiser(){

    afficherBienvenue();

    std::string nom;

    for(int i = 0; i < 2; i++){

        std::cout << "Entrez le nom du joueur " << i + 1 << " : ";
        std::cin >> nom;
        m_joueurs.push_back(Joueur(nom));
    }

    m_joueurCourant = 0;

    std::cout << "Souhaitez vous jouer en mode rapide ? (1 = Oui, 0 = Non) : ";
    int choix = verifSaisieNumero();

    while(choix != 0 && choix != 1){
        std::cout << "Choix invalide, tapez 1 ou 0 : ";
        choix = verifSaisieNumero();
    }

    m_modeRapide = (choix == 1);
    ajouterHistorique("Debut de partie : " + m_joueurs[0].getNomJoueur() + " contre " + m_joueurs[1].getNomJoueur() + ".");
    ajouterHistorique(m_modeRapide ? "Mode rapide." : "Mode classique.");


    // Liste des cartes Royaume disponibles pour la selection
    std::vector<std::string> cartesRoyaume = {
        "Atelier",
        "Bucheron",
        "Chapelle",
        "Douves",
        "Festin",
        "Jardins",
        "Laboratoire",
        "Sorciere",
        "Village",
        "Voleur",
        "Espion",
        "Milice"
    };

    // Contient les dix cartes Royaume choisies pour la partie
    std::vector<std::string> cartesChoisies;

    bool selectionConfirmee = false;

    // Permet de recommencer la selection si elle n'est pas confirmee
    while(!selectionConfirmee){

        cartesChoisies.clear();

        // Le joueur doit selectionner exactement dix cartes differentes
        while(cartesChoisies.size() < 10){

            std::cout << "\n========================================\n";
            std::cout << "         CHOIX DES CARTES ROYAUME       \n";
            std::cout << "========================================\n";

            std::cout << "Choisissez 10 cartes Royaume parmi les cartes disponibles.\n";
            std::cout << "Vous pouvez consulter une carte avant de la selectionner.\n\n";

            // Afficher les noms et les numeros des cartes Royaume
            for(int i = 0; i < static_cast<int>(cartesRoyaume.size()); i++){

                std::cout << i + 1 << ". " << cartesRoyaume[i];

                // Indiquer si la carte a deja ete selectionnee a cote de son nom
                for(const std::string& carte : cartesChoisies){

                    if(carte == cartesRoyaume[i]){
                        std::cout << " [Selectionnee]";
                        break;
                    }
                }

                std::cout << "\n";
            }

            std::cout << "\n----------------------------------------\n";
            std::cout << "Cartes selectionnees : "
                      << cartesChoisies.size() << " / 10\n";

            std::cout << "\n1. Selectionner une carte\n";
            std::cout << "2. Consulter une carte\n";
            std::cout << "Votre choix : ";

            int option = verifSaisieNumero();

            if(option != 1 && option != 2){
                std::cout << "Option invalide, tapez 1 ou 2.\n";
                option = verifSaisieNumero();
            }

            std::cout << "Entrez le numero de la carte : ";
            int numero = verifSaisieNumero();

            // Verifier que le numero correspond a une carte Royaume
            if(numero < 1 || numero > static_cast<int>(cartesRoyaume.size())){
                std::cout << "Numero de carte invalide.\n";
                continue;
            }

            std::string nomCarte = cartesRoyaume[numero - 1];

            // Consulter une carte sans la selectionner
            if(option == 2){

                m_reserve.afficherCarteRoyaume(nomCarte);
                continue;
            }

            // Verifier si la carte est deja selectionnee
            bool dejaChoisie = false;

            for(const std::string& carte : cartesChoisies){

                if(carte == nomCarte){
                    dejaChoisie = true;
                    break;
                }
            }

            if(dejaChoisie){
                std::cout << "Cette carte a deja ete selectionnee.\n";
                continue;
            }

            // Ajouter la carte a la selection
            cartesChoisies.push_back(nomCarte);

            std::cout << nomCarte << " selectionnee !\n";
        }

        // Afficher les dix cartes Royaume selectionnees
        std::cout << "\n========================================\n";
        std::cout << "           VOTRE SELECTION             \n";
        std::cout << "========================================\n";

        for(int i = 0; i < static_cast<int>(cartesChoisies.size()); i++){
            std::cout << i + 1 << ". " << cartesChoisies[i] << "\n";
        }

        std::cout << "\nConfirmer cette selection ? "
                  << "(1 = Oui, 0 = Recommencer) : ";

        int confirmation = verifSaisieNumero();

        while(confirmation != 0 && confirmation != 1){
            std::cout << "Choix invalide, tapez 1 ou 0 : ";
            confirmation = verifSaisieNumero();
        }

        selectionConfirmee = (confirmation == 1);
    }


    // Initialiser la reserve avec les dix cartes Royaume choisies
    m_reserve.initialiser(m_modeRapide, cartesChoisies);
    for(const std::string& nomCarte : cartesChoisies)
        ajouterHistorique("Carte Royaume selectionnee : " + nomCarte + ".");

    // Enregistrer les cartes créées dans la réserve
    m_toutesLesCartes = m_reserve.getToutesLesCartes();


    // Creer les decks initiaux des deux joueurs
    for(int j = 0; j < 2; j++){

        for(int i = 0; i < 7; i++){
            Carte* carte = new CarteTresor(1, "Cuivre", 0);
            m_joueurs[j].ajouterAuDeck(carte);
            m_toutesLesCartes.push_back(carte);
        }

        for(int i = 0; i < 3; i++){
            Carte* carte = new CarteVictoire(1, "Domaine", 2);
            m_joueurs[j].ajouterAuDeck(carte);
            m_toutesLesCartes.push_back(carte);
        }
    }


    // Melanger les decks et distribuer cinq cartes a chaque joueur
    for(int j = 0; j < 2; j++){
        m_joueurs[j].melanger();
        m_joueurs[j].piocher(5);
        ajouterHistorique(m_joueurs[j].getNomJoueur() + " commence avec 7 Cuivre et 3 Domaine, puis pioche 5 cartes.");
    }
}


// Change le joueur courant pour passer au joueur suivant.
void Partie::changerJoueur(){

    if(m_joueurCourant == 0){
        m_joueurCourant = 1;
    }
    else{
        m_joueurCourant = 0;
    }
}


// Lance les tours jusqu'à la fin de la partie, puis détermine le gagnant.
void Partie::jouer(){

    while(!estTerminee()){

        jouerTour();

        if(!estTerminee()){
            changerJoueur();
        }
    }

    ajouterHistorique("Fin de partie : condition de fin atteinte dans la reserve.");
    determinerGagnant();
    int score0 = m_joueurs[0].calculerScore();
    int score1 = m_joueurs[1].calculerScore();
    if(score0 > score1 || (score0 == score1 && m_joueurs[0].getNombreTours() < m_joueurs[1].getNombreTours()))
        ajouterHistorique("Vainqueur : " + m_joueurs[0].getNomJoueur() + ".");
    else if(score1 > score0 || (score0 == score1 && m_joueurs[1].getNombreTours() < m_joueurs[0].getNombreTours()))
        ajouterHistorique("Vainqueur : " + m_joueurs[1].getNomJoueur() + ".");
    else
        ajouterHistorique("Victoire partagee.");
    afficherHistorique();

    std::cout << "\n========== STATISTIQUES FINALES ==========\n";

    for(const Joueur& joueur : m_joueurs){
        joueur.afficherStatistiques();
    }
}


// achete une carte de la reserve pour le joueur courant
void Partie::acheterCarte(const std::string& nom){

    Joueur& joueur = m_joueurs[m_joueurCourant];
    Carte* carte = m_reserve.retirerCarte(nom);

    if(carte != nullptr){
        joueur.recevoir(carte);
        joueur.ajouterPieces(-carte->getCout());
        joueur.ajouterAchats(-1);
        ajouterHistorique(joueur.getNomJoueur() + " achete " + carte->getNom() + ".");
    }
}


// Vérifie si la réserve remplit une condition de fin de partie.
bool Partie::estTerminee(){

    return m_reserve.conditionFinAtteinte();
}


// Détermine le gagnant selon les scores des joueurs
void Partie::determinerGagnant(){

    int score1 = m_joueurs[0].calculerScore();
    int score2 = m_joueurs[1].calculerScore();
    ajouterHistorique("Scores finaux : " + m_joueurs[0].getNomJoueur() + " = " + std::to_string(score1) + ", " + m_joueurs[1].getNomJoueur() + " = " + std::to_string(score2) + ".");

    if(score1 > score2){
        std::cout << "Le joueur : " << m_joueurs[0].getNomJoueur()
                  << " a gagné !" << std::endl;
    }
    else if(score2 > score1){
        std::cout << "Le joueur : " << m_joueurs[1].getNomJoueur()
                  << " a gagné !" << std::endl;
    }
    else{
        std::cout << "Les deux joueurs ont le meme score !" << std::endl;

        int tour1 = m_joueurs[0].getNombreTours();
        int tour2 = m_joueurs[1].getNombreTours();

        if(tour1 < tour2){
            std::cout << "Le joueur : " << m_joueurs[0].getNomJoueur()
                      << " a gagné !" << std::endl;
        }
        else if(tour2 < tour1){
            std::cout << "Le joueur : " << m_joueurs[1].getNomJoueur()
                      << " a gagné !" << std::endl;
        }
        else{
            std::cout << "Les deux joueurs partagent la victoire !" << std::endl;
        }
    }

  
}


// Gère la phase Action du joueur courant à l'aide des méthodes de Joueur.
void Partie::phaseAction(){

    afficherPhase("Action");
    std::cout << "Vous pouvez jouer une carte Action de votre main que si vous en avez.\n";
    

    std::string reponse;
    int numero;

    Joueur& joueur = m_joueurs[m_joueurCourant];
    std::cout << "\nAu tour de : " << joueur.getNomJoueur() << std::endl;

    while(joueur.getActions() > 0 && joueur.aCarte(ACTION)){

        joueur.afficher_main();

        std::cout << "Voulez-vous jouer une carte Action ? o/n : ";
        std::cin >> reponse;

        while (reponse != "o" && reponse != "n"){
            std :: cout << "Reponse invalide, tapez o ou n : ";
            std::cin >> reponse;
        }

        if(reponse == "n"){
            break;
        }

        if(reponse == "o"){

            std::cout << "Entrez le numero de la carte : ";
            numero = verifSaisieNumero();

            Carte* carte_select = joueur.getCarteMain(numero);

            joueur.jouerAction(carte_select, *this);
            afficherCompteurs();
        }
    }
}


// Gère les achats du joueur courant en consultant la réserve.
void Partie::phaseAchat(){

    afficherPhase("Achat");

    std::string reponse;
    int numero;

    Joueur& joueur = m_joueurs[m_joueurCourant];

    std::cout << "\nEtape 1 : Jouer les Tresors\n";

    std::cout << "\nJouez vos cartes Tresor pour obtenir des pieces." << std::endl;
    std::cout << "Vous pouvez jouer plusieurs Tresors avant d'acheter." << std::endl;

    // Jouer les cartes Trésor de la main
    while(joueur.aCarte(TRESOR)){

        joueur.afficher_main();

        std::cout << "Choisissez un Tresor a jouer "
                  << "(0 pour passer aux achats / 99 pour jouer tous les Tresors) : ";

        numero = verifSaisieNumero();

        if(numero == 0){
            std::cout << "Fin de la selection des Tresors.\n";
            break;
        }

        // 99 pour jouer toutes les cartes Tresor d'un coup
        if(numero == 99){

            int i = 1;

            while(joueur.aCarte(TRESOR)){

                Carte* carte = joueur.getCarteMain(i);

                if(carte != nullptr && carte->getType() == TRESOR){
                    int piecesAvant = joueur.getPieces();
                    joueur.jouerTresor(carte);
                    if(joueur.getPieces() > piecesAvant)
                        ajouterHistorique(joueur.getNomJoueur() + " joue " + carte->getNom() + " : +" + std::to_string(joueur.getPieces() - piecesAvant) + " piece(s).");
                }
                else{
                    i++;
                }
            }

            afficherCompteurs();
            break;
        }

        Carte* carte = joueur.getCarteMain(numero);

        int piecesAvant = joueur.getPieces();
        joueur.jouerTresor(carte);
        if(carte != nullptr && joueur.getPieces() > piecesAvant)
            ajouterHistorique(joueur.getNomJoueur() + " joue " + carte->getNom() + " : +" + std::to_string(joueur.getPieces() - piecesAvant) + " piece(s).");
        afficherCompteurs();
    }

    std::cout << "\nEtape 2 : Acheter des cartes\n";
    std::cout << "Pieces disponibles : " << joueur.getPieces() << std::endl;
    std::cout << "Choisissez une carte dont le prix ne depasse pas vos pieces.\n";

    // Acheter des cartes dans la réserve
    while(joueur.getAchats() > 0) // pas besoin de verif si joueur a carte tresor main car cuivre vaut 0
    {
        m_reserve.afficher_reserve();

        std::cout << "Voulez-vous acheter une carte ? "
                  << "(o = oui, n = terminer les achats) : " << std::endl;

        std::cin >> reponse;
        while (reponse != "o" && reponse != "n"){
            std :: cout << "Reponse invalide, tapez o ou n : ";
            std::cin >> reponse;
        }

        if(reponse == "n"){
            break;
        }
        else if(reponse == "o"){

            std::cout << "Entrez le numero de la carte a acheter : ";
            numero = verifSaisieNumero();

            std::string carte_select = m_reserve.getNom(numero);

            if(carte_select != ""){

                if(m_reserve.estDisponible(carte_select)){

                    int prix_carte_select = m_reserve.getCout(carte_select);

                    if(joueur.getPieces() >= prix_carte_select){

                        acheterCarte(carte_select);
                        afficherCompteurs();
                    }
                    else{
                        std::cout << "Vous ne possedez pas assez de pieces" << std::endl;
                    }
                }
                else{
                    std::cout << "Cette carte n'est plus disponible" << std::endl;
                }
            }
            else{
                std::cout << "Il faut choisir une carte presente dans la reserve" << std::endl;
            }
        }
    }
}


// Termine le tour du joueur courant en appelant Joueur::ajuster().
void Partie::phaseAjustement(){

    afficherPhase("Ajustement");
    std::cout << "Defausse des cartes restantes et des cartes jouees.\n";
    std::cout << "Pioche de 5 nouvelles cartes.\n";

    Joueur& joueur = m_joueurs[m_joueurCourant];
    joueur.ajuster(this);
    ajouterHistorique(joueur.getNomJoueur() + " termine son tour et pioche " + std::to_string(joueur.getNombreCartesMain()) + " cartes.");
}


// Enchaîne les trois phases du tour du joueur courant.
void Partie::jouerTour(){

    ajouterHistorique("--- Tour de " + m_joueurs[m_joueurCourant].getNomJoueur() + " ---");
    afficherDebutTour();
    afficherCompteurs();

    ajouterHistorique("Phase Action de " + m_joueurs[m_joueurCourant].getNomJoueur() + ".");
    phaseAction();
    ajouterHistorique("Phase Achat de " + m_joueurs[m_joueurCourant].getNomJoueur() + ".");
    phaseAchat();
    ajouterHistorique("Phase Ajustement de " + m_joueurs[m_joueurCourant].getNomJoueur() + ".");
    phaseAjustement();

    m_joueurs[m_joueurCourant].ajouterTour();
}


std::vector<Joueur>& Partie::getJoueurs(){

    return m_joueurs;
}


Reserve& Partie::getReserve(){

    return m_reserve;
}


void Partie::mettreAurebut(Carte* carte){

    if(carte != nullptr){
        m_rebut.push_back(carte);
        ajouterHistorique(carte->getNom() + " est mise au rebut.");
    }
}



void Partie::ajouterHistorique(const std::string& evenement){
    m_historique.push_back(evenement);
}

void Partie::afficherHistorique() const{
    std::cout << "\n========== HISTORIQUE DE LA PARTIE ==========\n";
    if(m_historique.empty()) std::cout << "Aucun evenement enregistre.\n";
    for(const std::string& evenement : m_historique)
        std::cout << evenement << '\n';

}
