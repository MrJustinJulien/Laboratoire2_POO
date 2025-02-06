#ifndef ENTREPOT_H
#define ENTREPOT_H

#include <string>
#include <list>
#include "Compteur.h"
#include "Composant.h"

using namespace std;

class Entrepot
{
public:
    Entrepot();
    Entrepot(const Entrepot& entrepot);
    ~Entrepot();

    void ajouterComposants(list <Composant*> listeComposants, int id);
    void ajouterComposant(Composant* composant, int id);
    Composant* recupererComposant(int id);
    int getQuantiteComposants(int id) const { return static_cast <int>(composants[id].size()); }

private:
    list <Composant*> composants[5];
};

#endif

