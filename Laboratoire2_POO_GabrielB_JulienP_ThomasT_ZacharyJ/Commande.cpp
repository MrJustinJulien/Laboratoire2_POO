#include <iostream>
#include "Commande.h"

using namespace std;

Commande::Commande(int noCommande, int qteProduits[]) :
	noCommande(noCommande)
{
	for (int i = 0; i < 5; i++)
	{
		quantiteProduits[i] = validerQuantite(qteProduits[i]);
	}
	Compteur::ajouterConstructeur();
}

Commande::Commande(const Commande& commande) :
	noCommande(commande.noCommande)
{
	for (int i = 0; i < 5; i++)
	{
		quantiteProduits[i] = validerQuantite(commande.quantiteProduits[i]);
	}
	Compteur::ajouterConstructeurCopie();
}

Commande::~Commande()
{
	Compteur::ajouterDestructeur();
}

int Commande::validerQuantite(int q)
{
	if (q < 0)
	{
		return 0;
	}
	else if (q > 10)
	{
		return 10;
	}
	return q;
}

int Commande::getQuantiteProduit(int idProduit) const
{
	if (idProduit < 0 || idProduit >= 5)
	{
		return 0;
	}
	return quantiteProduits[idProduit];
}

ostream& operator<<(ostream& out, const Commande& commande)
{
	out << "--------------------------------------" << endl
		<< "COMMANDE" << endl << "No de commande: "
		<< commande.getNoCommande() << endl;
	for (int i = 0; i < 5; i++)
	{
		out << "Produit demande {" << i << "} --> " << commande.getQuantiteProduit(i) << endl;
	}
	out << "--------------------------------------" << endl;
	return out;
}
