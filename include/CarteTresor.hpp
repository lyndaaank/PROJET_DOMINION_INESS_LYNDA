
#ifndef __CARTETRES__H
#define __CARTETRES__H
#include <string>
#include "Carte.hpp"

class CarteTresor : public Carte{

private :
    int m_Valeur;

public :
    CarteTresor(int tresors, std :: string nom, int cout, std :: string type);
    int getValeur()const;
    ~CarteTresor();
};

#endif
