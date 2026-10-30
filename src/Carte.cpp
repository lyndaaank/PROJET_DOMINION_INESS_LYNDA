#include "Carte.hpp"
#include <iostream>


Carte::Carte(const std::string& nom, int cout, TypeCarte type)
    : m_nom(nom), m_cout(cout), m_type(type)
{
   
}


Carte::~Carte()
{

}




std::string Carte::getNom() const
{

    return m_nom;
}


int Carte::getCout() const
{

    return m_cout;
}


TypeCarte Carte::getType() const
{

    return m_type;
}


void Carte::appliquerEffet(Joueur& /*joueur*/, Partie& /*partie*/)
{


    // Aucun effet par defaut
}


std::vector<std::string> Carte::getDescription()const{
    return {};
}


std::string Carte::getLigne(const std::string texte) const{

    std::string ligne = "| " + texte;

    for(int i = texte.size(); i < 20; i++){
        ligne += " ";
    }

    ligne += " |";

    return ligne;
}


std::vector<std::string> Carte::getAffichage(int numero) const{

    std::vector<std::string> lignes;

    lignes.push_back("+----------------------+");

    lignes.push_back(getLigne(std::to_string(numero) + ") " + m_nom));
    lignes.push_back(getLigne("Cout : " + std::to_string(m_cout)));
    lignes.push_back(getLigne(""));

    lignes.push_back("|----------------------|");


    std::vector<std::string> description = getDescription();

    for(int i = 0; i < 7; i++){

        if(i < static_cast<int>(description.size())){
            lignes.push_back(getLigne(description[i]));
        }
        else{
            lignes.push_back(getLigne(""));
        }
    }

    lignes.push_back("+----------------------+");

    return lignes;
}










