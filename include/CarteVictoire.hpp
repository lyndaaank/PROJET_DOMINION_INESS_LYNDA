
#ifndef __CARTEVICT__H
#define __CARTEVICT__H
#include <string>
#include "Carte.hpp"

class CarteVictoire : public Carte{

private :
    int m_Points;

public :
    virtual int calculerPoints(const Joueur& joueur) const; 
    CarteVictoire(int points, std :: string nom, int cout, std :: string type);
    int getPoints()const;
    ~CarteVictoire();
};

#endif
