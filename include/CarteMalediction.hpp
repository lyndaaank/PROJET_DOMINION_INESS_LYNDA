
#ifndef __CARTEMALED__H
#define __CARTEMALED__H
#include <string>
#include "Carte.hpp"

class CarteMalediction: public Carte{

private :
    int m_Points;

public :
    CarteMalediction(int points, const std::string& nom, int cout);
    int getPoints()const;
    std::vector<std::string> getDescription() const override;
    ~CarteMalediction();
};

#endif
