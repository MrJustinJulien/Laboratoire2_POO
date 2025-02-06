#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include <string>
#include <list>
#include "Compteur.h"

#include "ProduitA.h"
#include "ProduitB.h"
#include "ProduitC.h"
#include "ProduitD.h"
#include "ProduitE.h"

using namespace std;

class Inventaire
{
public:
	Inventaire();
	Inventaire(const Inventaire& inventaire);
	~Inventaire();

	void ajouterProduit(ProduitA* produit) { ajouterProduit(produit, 0); }
	void ajouterProduit(ProduitB* produit) { ajouterProduit(produit, 1); }
	void ajouterProduit(ProduitC* produit) { ajouterProduit(produit, 2); }
	void ajouterProduit(ProduitD* produit) { ajouterProduit(produit, 3); }
	void ajouterProduit(ProduitE* produit) { ajouterProduit(produit, 4); }
	Produit* recupererProduit(int idProduit);

private:
	list <Produit*> produits[5];
	void ajouterProduit(Produit* produit, int idProduit);
};

#endif

