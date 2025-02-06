#ifndef COMPOSANT2_H
#define COMPOSANT2_H

#include "Composant.h"

using namespace std;

class Composant2 : public Composant
{
public:
	Composant2(int qualite, int prix) :
		Composant("COMPOSANT #2", 7, qualite, prix)
	{
		Compteur::ajouterConstructeur();
	}
	Composant2(const Composant2& composant2) :
		Composant(composant2)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~Composant2()
	{
		Compteur::ajouterDestructeur();
	}

private:

};

#endif
