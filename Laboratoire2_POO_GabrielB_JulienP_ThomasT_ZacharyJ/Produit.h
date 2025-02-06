#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <list>
#include "Compteur.h"
#include "Composant.h"

using namespace std;

class Produit
{
public:
	Produit(string nom);
	Produit(const Produit& p);
	virtual ~Produit();

	void ajouterComposant(Composant* composant) { composants.push_back(composant); }
	string getNom() const { return nom; }
	virtual string getDescription() const { return ""; }
	int evaluerQualite() const;
	friend ostream& operator<<(ostream& out, const Produit& produit);

private:
	int calculerPoids() const;
	int calculerPrix() const;
	string nom;
	list <Composant*> composants;
};
#endif

