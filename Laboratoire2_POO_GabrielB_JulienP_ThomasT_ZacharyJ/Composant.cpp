#include <iostream>
#include "Composant.h"

using namespace std;

Composant::Composant(string nom, int poids, int qualite, int prix) :
    nom(nom)
{
    if (poids >= 0)
    {
        this->poids = poids;
    }
    else
    {
        this->poids = 0;
    }

    if (qualite >= 0 && qualite <= 100)
    {
        this->qualite = qualite;
    }
    else if (qualite > 100)
    {
        this->qualite = 100;
    }
    else
    {
        this->qualite = 0;
    }

    if (prix > 0)
    {
        this->prix = prix;
    }
    else
    {
        this->prix = 0;
    }

    Compteur::ajouterConstructeur();
}

Composant::Composant(const Composant& composant) :
    poids(composant.poids), qualite(composant.qualite), prix(composant.prix)
{
    this->nom = composant.nom;
    Compteur::ajouterConstructeurCopie();
}

Composant::~Composant()
{
    Compteur::ajouterDestructeur();
}
