
#ifndef __CARTETRES__H
#define __CARTETRES__H
#include <string>
#include "Carte.hpp"

class CarteTresor : public Carte{

private :
    int m_Valeur;

public :
    CarteTresor(int tresors, const std::string& nom, int cout);
    int getValeur()const;
    std::vector<std::string> getDescription() const override;
    ~CarteTresor();
};

#endif
