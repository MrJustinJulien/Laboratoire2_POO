#include <iostream>
#include "Compteur.h"

using namespace std;

int Compteur::constructeur = 0;
int Compteur::constructeurCopie = 0;
int Compteur::destructeur = 0;

Compteur::Compteur()
{
	ajouterConstructeur();
}

Compteur::Compteur(const Compteur& compteur)
{
	ajouterConstructeurCopie();
}

Compteur::~Compteur()
{
	ajouterDestructeur();
}
