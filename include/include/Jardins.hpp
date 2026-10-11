
#ifndef __JARDINS__H
#define __JARDINS__H
#include <string>
#include "CarteVictoire.hpp"

class Jardins : public CarteVictoire{

public :
    Jardins();
    void calculerPoints(const Joueur& joueur)const override;
    ~Jardins();
};

#endif
