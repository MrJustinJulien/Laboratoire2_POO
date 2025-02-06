#include <iostream>
#include "Inventaire.h"

using namespace std;

Inventaire::Inventaire()
{
	Compteur::ajouterConstructeur();
}

Inventaire::Inventaire(const Inventaire& inventaire)
{
	for (int i = 0; i < 5; i++)
	{
		for (Produit* produit : inventaire.produits[i])
		{
			produits[i].push_back(new Produit(*produit));
		}
	}

	Compteur::ajouterConstructeurCopie();
}

Inventaire::~Inventaire()
{
	for (int i = 0; i < 5; i++)
	{
		for (Produit* produit : produits[i])
		{
			delete produit;
		}
	}

	Compteur::ajouterDestructeur();
}

void Inventaire::ajouterProduit(Produit* produit, int idProduit)
{
	if (idProduit >= 0 && idProduit < 5)
	{
		produits[idProduit].push_back(produit);
	}
}

Produit* Inventaire::recupererProduit(int idProduit)
{
	Produit* produit = produits[idProduit].front();
	produits[idProduit].pop_front();
	return produit;
}
