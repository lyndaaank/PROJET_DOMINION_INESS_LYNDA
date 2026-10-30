
#ifndef __JARDINS__H
#define __JARDINS__H
#include <string>
#include "CarteVictoire.hpp"

class Jardins : public CarteVictoire{

public :
    Jardins();
    int calculerPoints(const Joueur& joueur)const override;
    std::vector<std::string> getDescription() const override;
    ~Jardins();
};

#endif
