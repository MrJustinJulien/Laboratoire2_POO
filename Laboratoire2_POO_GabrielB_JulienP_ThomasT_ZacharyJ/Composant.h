#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <string>
#include "Compteur.h"

using namespace std;

class Composant
{
protected:
	Composant(string nom, int poids, int qualite, int prix);

public:
	Composant(const Composant&);
	virtual ~Composant();

	string getNom() const { return nom; }
	int getPoids() const { return poids; }
	int getQualite() const { return qualite; }
	int getPrix() const { return prix; }

private:
	string nom;
	int poids;
	int qualite;
	int prix;
};

#endif 

