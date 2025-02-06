#ifndef PRODUITB_H
#define PRODUITB_H

#include <string>
#include "Produit.h"

using namespace std;

class ProduitB : public Produit
{
public:
	ProduitB() :
		Produit("PRODUIT B")
	{
		Compteur::ajouterConstructeur();
	}
	ProduitB(const ProduitB& produitB) :
		Produit(produitB)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~ProduitB()
	{
		Compteur::ajouterDestructeur();
	}

	virtual string getDescription() const override { return "Description d'un produit B"; }

private:

};

#endif

