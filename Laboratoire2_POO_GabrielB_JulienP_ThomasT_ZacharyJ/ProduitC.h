#ifndef PRODUITC_H
#define PRODUITC_H

#include <string>
#include "Produit.h"

using namespace std;

class ProduitC : public Produit
{
public:
	ProduitC() :
		Produit("PRODUIT C")
	{
		Compteur::ajouterConstructeur();
	}
	ProduitC(const ProduitC& produitC) :
		Produit(produitC)
	{
		Compteur::ajouterConstructeur();
	}
	~ProduitC()
	{
		Compteur::ajouterDestructeur();
	}
	virtual string getDescription() const override { return "Description d'un produit C"; }

private:

};

#endif
