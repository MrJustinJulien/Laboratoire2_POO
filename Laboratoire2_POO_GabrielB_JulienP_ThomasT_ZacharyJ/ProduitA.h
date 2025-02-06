#ifndef PRODUITA_H
#define PRODUITA_H

#include <string>
#include "Produit.h"
#include "Compteur.h"

using namespace std;

class ProduitA : public Produit
{
public:
	ProduitA() :
		Produit("PRODUIT A")
	{
		Compteur::ajouterConstructeur();
	}
	ProduitA(const ProduitA& produitA) :
		Produit(produitA)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~ProduitA()
	{
		Compteur::ajouterDestructeur();
	}

	virtual string getDescription() const override { return "Description d'un produit A"; }

private:

};

#endif