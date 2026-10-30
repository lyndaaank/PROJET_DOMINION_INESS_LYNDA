#ifndef CARTE_HPP
#define CARTE_HPP

#include<iostream>
#include<string>
#include<vector>

class Joueur;
class Partie;

enum TypeCarte {
    TRESOR,
    VICTOIRE,
    MALEDICTION,
    ACTION


};


class Carte{

private:

    std::string m_nom;
    int m_cout;
    TypeCarte m_type;

public:

    Carte(const std::string& nom, int cout, TypeCarte type);
    virtual ~Carte(); //destructeur necessaire ici
   
    std::string getNom() const;
    int getCout() const;
    TypeCarte getType() const;

    virtual void appliquerEffet(Joueur& joueur, Partie& partie);
    std::string getLigne(const std::string texte) const; 
    std::vector<std::string> getAffichage(int numero) const;

    virtual std::vector<std::string> getDescription() const;

};

#endif

