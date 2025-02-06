#ifndef COMPOSANT5_H
#define COMPOSANT5_H

#include "Composant.h"

using namespace std;

class Composant5 : public Composant
{
public:
	Composant5(int variation, int qualite, int prix) :
		Composant("COMPOSANT #5", 10 + variation, qualite, prix)
	{
		Compteur::ajouterConstructeur();
	}
	Composant5(const Composant5& composant5) :
		Composant(composant5)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~Composant5()
	{
		Compteur::ajouterDestructeur();
	}

private:

};

#endif
