
#ifndef __CARTEVICT__H
#define __CARTEVICT__H
#include <string>
#include "Carte.hpp"

class Joueur;

class CarteVictoire : public Carte{

private :
    int m_Points;

public :
    virtual int calculerPoints(const Joueur& joueur) const; 
    CarteVictoire(int points, const std::string& nom, int cout);
    int getPoints()const;

    std::vector<std::string> getDescription() const override;
    ~CarteVictoire();
};

#endif
