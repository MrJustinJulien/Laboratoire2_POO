#ifndef COMPOSANT1_H
#define COMPOSANT1_H

#include "Composant.h"

using namespace std;

class Composant1 : public Composant
{
public:
	Composant1(int qualite, int prix) :
		Composant("COMPOSANT #1", 10, qualite, prix)
	{
		Compteur::ajouterConstructeur();
	}
	Composant1(const Composant1& composant1) :
		Composant(composant1)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~Composant1()
	{
		Compteur::ajouterDestructeur();
	}

private:

};

#endif
