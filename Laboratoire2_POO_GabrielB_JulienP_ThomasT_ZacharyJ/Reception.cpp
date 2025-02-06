#include <iostream>
#include "Reception.h"

using namespace std;

Reception::Reception(BonCommande* bonCommande) :
	bonCommande(bonCommande)
{
	Compteur::ajouterConstructeur();
}

Reception::~Reception()
{
	for (int i = 0; i < 5; i++)
	{
		for (Produit* produit : produits[i])
		{
			delete produit;
		}
		produits[i].clear();
	}
	delete bonCommande;

	Compteur::ajouterDestructeur();
}

void Reception::ajouterProduit(Produit* produit, int id)
{
	if (id >= 0 && id < 5)
	{
		produits[id].push_back(produit);
	}
}

ostream& operator<<(ostream& out, const Reception& reception)
{
	out << "--------------------------------------" << endl
		<< "RECEPTION" << endl
		<< "Bon de commande : " << reception.getBonCommande()->getIdBonCommande() << endl;
	for (int i = 0; i < 5; i++)
	{
		const list <Produit*>& produits = reception.produits[i];
		for (const Produit* produit : produits)
		{
			out << "- Produit recu --> " << *produit << endl;
		}
	}
	out << "--------------------------------------";

	return out;
}
