#ifndef PRODUITD_H
#define PRODUITD_H

#include <string>
#include "Produit.h"

using namespace std;

class ProduitD : public Produit
{
public:
	ProduitD() :
		Produit("PRODUIT D")
	{
		Compteur::ajouterConstructeur();
	}
	ProduitD(const ProduitD& produitD) :
		Produit(produitD)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~ProduitD()
	{
		Compteur::ajouterDestructeur();
	}

	virtual string getDescription() const override { return "Description d'un produit D"; }

private:

};

#endif