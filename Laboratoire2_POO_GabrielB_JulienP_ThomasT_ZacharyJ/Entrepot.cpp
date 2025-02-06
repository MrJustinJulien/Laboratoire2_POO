#include <iostream>
#include "Entrepot.h"

using namespace std;

Entrepot::Entrepot()
{
    Compteur::ajouterConstructeur();
}

Entrepot::Entrepot(const Entrepot& entrepot)
{
    for (int i = 0; i < 5; ++i)
    {
        for (Composant* composant : entrepot.composants[i])
        {
            composants[i].push_back(new Composant(*composant));
        }
    }

    Compteur::ajouterConstructeurCopie();
}

Entrepot::~Entrepot()
{
    for (int i = 0; i < 5; ++i) {
        for (Composant* composant : composants[i])
        {
            delete composant;
        }
        composants[i].clear();
    }

    Compteur::ajouterDestructeur();
}

void Entrepot::ajouterComposants(list <Composant*> listeComposants, int id)
{
    for (Composant* composant : listeComposants)
    {
        ajouterComposant(composant, id);
    }
}

void Entrepot::ajouterComposant(Composant* composant, int id)
{
    if (id >= 0 && id < 5)
    {
        composants[id].push_back(composant);
    }
}

Composant* Entrepot::recupererComposant(int id)
{
    if (id < 0 || id >= 5 || composants[id].empty())
    {
        return nullptr;
    }

    Composant* composant = composants[id].front();
    composants[id].pop_front();
    return composant;
}
