#ifndef COMPOSANT3_H
#define COMPOSANT3_H

#include "Composant.h"

using namespace std;

class Composant3 : public Composant
{
public:
	Composant3(int prix) :
		Composant("COMPOSANT #3", 12, 100, prix)
	{
		Compteur::ajouterConstructeur();
	}
	Composant3(const Composant3& composant3) :
		Composant(composant3)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~Composant3()
	{
		Compteur::ajouterDestructeur();
	}

private:

};

#endif
