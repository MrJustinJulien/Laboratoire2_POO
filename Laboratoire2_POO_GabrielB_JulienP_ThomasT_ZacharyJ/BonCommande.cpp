#include <iostream>
#include "BonCommande.h"

using namespace std;

BonCommande::BonCommande(int idBonCommande, Commande* commande) :
	idBonCommande(idBonCommande), commande(commande)
{
	for (int i = 0; i < 5; i++)
	{
		quantiteProduits[i] = 0;
	}

	Compteur::ajouterConstructeur();
}

BonCommande::BonCommande(const BonCommande& bonCommande) :
	idBonCommande(bonCommande.idBonCommande), commande(bonCommande.commande)
{
	for (int i = 0; i < 5; i++)
	{
		quantiteProduits[i] = bonCommande.quantiteProduits[i];
	}

	Compteur::ajouterConstructeurCopie();
}

BonCommande::~BonCommande()
{
	Compteur::ajouterDestructeur();
}

void BonCommande::ajouterProduits(int quantite, int id)
{
	if (id >= 0 && id < 5)
	{
		quantiteProduits[id] = +quantite;
	}
}

ostream& operator<<(ostream& out, const BonCommande& bonCommande)
{
	out << "--------------------------------------" << endl
		<< "BON DE COMMANDE" << endl
		<< "Bon de commande : " << bonCommande.getIdBonCommande() << endl
		<< "No de commande : " << bonCommande.getCommande()->getNoCommande() << endl;
	for (int i = 0; i < 5; i++)
	{
		out << "- Produit {" << i << "} --> {commande: " << bonCommande.getCommande()->getQuantiteProduit(i)
			<< " / recu: " << bonCommande.getQuantiteProduits(i) << "}" << endl;
	}
	out << "--------------------------------------" << endl;

	return out;
}
