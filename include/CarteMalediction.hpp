
#ifndef __CARTEMALED__H
#define __CARTEMALED__H
#include <string>
#include "Carte.hpp"

class CarteMalediction: public Carte{

private :
    int m_Points;

public :
    CarteMalediction(int points, std :: string nom, int cout, std :: string type);
    int getPoints()const;
    ~CarteMalediction();
};

#endif
