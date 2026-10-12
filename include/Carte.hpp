#ifndef __CARTE__H
#define __CARTE__H

#include <string>

class Carte {

private :
    std :: string m_Nom;
    int m_Cout;
    std :: string m_Type;
public : 
    Carte(std :: string nom, int cout , std :: string type);

    std :: string getNom() const;
    int getCout() const;
    std :: string getType() const;

    ~Carte();


};
#endif 
