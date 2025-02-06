#ifndef PRODUITE_H
#define PRODUITE_H

#include <string>
#include "Produit.h"

using namespace std;

class ProduitE : public Produit
{
public:
	ProduitE() :
		Produit("PRODUIT E")
	{
		Compteur::ajouterConstructeur();
	}
	ProduitE(const ProduitE& produitE) :
		Produit(produitE)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~ProduitE()
	{
		Compteur::ajouterDestructeur();
	}

	virtual string getDescription() const override { return "Description d'un produit E"; }

private:

};

#endif
